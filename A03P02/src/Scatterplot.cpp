//
//  Scatterplot.cpp
//  A03
//
//  Created by Andrea Padula on 2/25/17.
//
//

#include "Scatterplot.h"
int size=5;
//ofEvent<ofVec2f> Scatterplot::clickedInside = ofEvent<ofVec2f>();

void Scatterplot::setup(std::vector<float> column1,std::vector<float> column2,int width, int height, int x, int y,std::string name1,std::string name2){
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->name1=name1;
    this->name2=name2;
    this->x_data=column1;
    this->y_data=column2;
    myFont.load("verdana.ttf", 10, true, true); //set the font
    myFont2.load("verdana.ttf", 8, true, true); //set the font
    if(!bRegisteredEvents) {
        ofRegisterMouseEvents(this); // this will enable our Canvas class to listen to the mouse events.
        bRegisteredEvents = true;
    }
    for(int i=0; i<500; i++) {
        section.push_back(false);
    }
}

void Scatterplot::setAxis(){
    float mx,my=0;
    if(view){
        maxY=ZmaxY;
        maxX=ZmaxX;
        mx=ZminX;
        my=ZminY;}
        ofPushMatrix();
        ofTranslate(x,y);
        ofSetColor(211,211,211);
        ofSetLineWidth(0.5);
        int space=height/ratio;
        int space2=height;
        float value=((float)maxY-float(my))/ratio;
        float t=my;
        for (int i=0; i<=ratio; i++) {
            
            stringstream stream;
            string s;
            if(t<999){
                stream << fixed << setprecision(1) << t;
                s = stream.str();}
            else{
                stream << fixed << setprecision(0) << t;
                s = stream.str();
            }
            ofSetColor(211,211,211);
            ofDrawLine(500, space2,0, space2);
            ofSetColor(0,0,0);
            myFont.drawString(s,  -40,space2);
            space2=space2-space;
            t=t+(value);
        }
        ofSetLineWidth(0.5);
        space=width/ratio;
        space2=0;
        value=((float)maxX-float(mx))/ratio;
        t=mx;
        for (int i=0; i<=ratio; i++) {
            stringstream stream;
            string s;
            if(t<999){
                stream << fixed << setprecision(1) << t;
                s = stream.str();}
            else{
                stream << fixed << setprecision(0) << t;
                s = stream.str();
            }
                
            ofSetColor(211,211,211);
            ofDrawLine(space2,0,space2, 500);
            ofSetColor(0,0,0);
            myFont.drawString(s, space2-10,width+20);
            space2=space2+space;
            t=t+(value);
            //break;
        }
        ofSetColor(0,0,0);
        ofSetLineWidth(2);
        ofVec3f arrowTailPoint (0,500,0);
        ofVec3f arrowHeadPoint (500, 500,0);
        ofDrawArrow(arrowTailPoint, arrowHeadPoint, 5.0);
        ofVec3f arrowTailPoint2 (0,500,0);
        ofVec3f arrowHeadPoint2 (0, 0,0);
        ofDrawArrow(arrowTailPoint2, arrowHeadPoint2, 5.0);
        
        ofRectangle bounds = myFont.getStringBoundingBox(name1, 0, 0);
        myFont.drawString(name1,(width/2)-(bounds.x/2), 540);
        
        ofRotateZ(-90.0);
        myFont.drawString(name2, -250, -45);
        
        ofPopMatrix();
}


void Scatterplot::draw(){
    
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(color);
    ofTranslate(x,y);
    ofDrawRectangle(0, 0, width, height);
    
    ofPopStyle();
    ofPopMatrix();
    setAxis();
    

    ofPushMatrix();
    ofTranslate(x,y);
    ofTranslate(0,height, 0);
    vector<float> tX;
    vector<float> tY;
    vector<float> tX2;
    vector<float> tY2;
    if(view){
        setValue();
        for (int i=0; i<x_zoom.size(); i++) {
            int x1=0;
            int y1=0;
            tX2.push_back(x_zoom[i]);
            tY2.push_back(y_zoom[i]);
            x1 = ofMap(x_zoom[i], ZminX, ZmaxX, 0, width);
            y1 = ofMap(y_zoom[i], ZminY, ZmaxY, 0, height);
            tX.push_back(x1);
            tY.push_back(y1);
            ofColor color = ofColor::fromHsb(150,x1/2,200);//choose the color
            ofSetColor( color );//set the color
            ofDrawCircle(x1,-y1,size);
        }
    }
    else{
        setValue();
    for (int i=0; i<x_data.size(); i++) {
        int x1=0;
        int y1=0;
        x1 = ofMap(x_data[i], minX, maxX, 0, width);
        y1 = ofMap(y_data[i], minY, maxY, 0, height);
        tX.push_back(x1);
        tY.push_back(y1);
        ofColor color = ofColor::fromHsb(150,x1/2,200);//choose the color
        ofSetColor( color );//set the color
        ofDrawCircle(x1,-y1,5);
    }
    }
    tranY=tY;
    tranX=tX;
    y_zoom2=tY2;
    x_zoom2=tX2;
    ofPopMatrix();

    if(selected){
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(0);
        
        ofDrawRectangle(sx0,sy0,65,20);
        stringstream stream;
        stringstream stream2;
        string s,s2;
        if(!view){
            if(x_data[index]<999){
            stream << fixed << setprecision(1) << x_data[index];
                s = stream.str();}
            else{
                stream << fixed << setprecision(0) << x_data[index];
                s = stream.str();}
            if(y_data[index]<999){
                stream2 << fixed << setprecision(1) << y_data[index];
                s2 = stream2.str();}
            else{
                stream2 << fixed << setprecision(0) << y_data[index];
                s2 = stream2.str();}
        }
        else
        {
            if(x_zoom[index]<999){
                stream << fixed << setprecision(1) << x_zoom[index];
                s = stream.str();}
            else{
                stream << fixed << setprecision(0) << x_zoom[index];
                s = stream.str();}
            if(y_zoom[index]<999){
                stream2 << fixed << setprecision(1) << y_zoom[index];
                s2 = stream2.str();}
            else{
                stream2 << fixed << setprecision(0) << y_zoom[index];
                s2 = stream2.str();}
        }
        s=" ("+s+","+s2+")";
        myFont2.drawString(s, sx0+2,sy0+10);
        ofFill();
    }
    if (zoom) {
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(0);
        ofDrawRectangle(sx2,sy2,sx3-sx2,sy3-sy2);
        ofFill();
    }
}

void Scatterplot::setValue(){
    if(!view){
        this-> maxX= *max_element(x_data.begin(), x_data.end())+1;
        this-> minX= *min_element(x_data.begin(), x_data.end())-1;
        this-> maxY= *max_element(y_data.begin(), y_data.end())+1;
        this-> minY= *min_element(y_data.begin(), y_data.end())-1;}
    else{
    this-> ZmaxX= *max_element(x_zoom.begin(), x_zoom.end())+1;
    this-> ZminX= *min_element(x_zoom.begin(), x_zoom.end())-1;
    this-> ZmaxY= *max_element(y_zoom.begin(), y_zoom.end())+1;
        this-> ZminY= *min_element(y_zoom.begin(), y_zoom.end())-1;}
}
void Scatterplot::mouseMoved(ofMouseEventArgs & args){
    
    if (inside(args.x, args.y)) {
        sx0 = args.x;
        sy0 = args.y;
        if(onPoint(sx0, sy0)){
            selected = true;
        
        }
        else
            selected=false;

    }
}
vector<float> tX11;
vector<float> tY11;
void Scatterplot::mouseDragged(ofMouseEventArgs & args) {

    tX11.clear();
    tY11.clear();
    if (zoom) {
        sx3 = args.x;
        sy3 = args.y;
        
        if (sx3 < x) {
            sx3 = x;
        }
        if (sx3 > x+width) {
            sx3 = x+width;
        }
        if (sy3 < y) {
            sy3 = y;
        }
        if (sy3 > y+height) {
            sy3 = y+height;
        }
        
        int z=0;
        for (int i=0; i<tranX.size(); i++) {
            section[i] = false;
            int minx=sx2,maxx=sx3,miny=sy2,maxy=sy3;
            if (sx2 > sx3) {
                minx = sx3; maxx = sx2;
            }
            if (sy2 > sy3) {
                miny = sy3; maxy = sy2;
            }
            if (ofInRange(tranX[i]+x,minx,maxx) &&
                ofInRange(height-tranY[i]+y,miny,maxy)) {
                section[i] = true;
                if (view){
                    tX11.push_back(x_zoom2[i]);
                    tY11.push_back(y_zoom2[i]);
                }
                else{
                tX11.push_back(x_data[i]);
                tY11.push_back(y_data[i]);}

            }
        }
        //ofNotifyEvent(brushedSelection, selected);
    }

}

void Scatterplot::mousePressed(ofMouseEventArgs & args){
    if (inside(args.x, args.y)) {
        zoom = true;
        sx2 = args.x;
        sy2 = args.y;
        sx3 = args.x;
        sy3 = args.y;
        for (int i=0; i<section.size(); i++) {
            section[i] = false;
        }
    }
}
void Scatterplot::mouseReleased(ofMouseEventArgs & args){
    if (inside(args.x, args.y)){
        if(args.button==2){
            view=false;
            zoom=false;
            ratio=10;
            setValue();
            size=5;
            return;
        }
    }
    zoom=false;
    for (int i=0; i<section.size(); i++) {
        if(section[i]==true){
            view=true;
            
            x_zoom=tX11;
            y_zoom=tY11;
            size++;
            if(ratio>1){
                ratio=ratio-1;
            }
            return;
        }
    }


}
void Scatterplot::mouseScrolled(ofMouseEventArgs & args){}
void Scatterplot::mouseEntered(ofMouseEventArgs & args){}
void Scatterplot::mouseExited(ofMouseEventArgs & args){}
//this function checks if the passed arguments are inside the Canvas.
bool Scatterplot::inside(float _x, float _y ){
    return (ofInRange(_x,x,x+width) &&
            ofInRange(_y,y,y+height));
    
}

bool Scatterplot::onPoint(float _x, float _y ){

        for (int i=0; i<tranX.size(); i++) {
            if((ofVec2f(_x-x,height-_y+y).distance(ofVec2f(tranX[i], tranY[i])) <3)==true){
                index=i;
                return true;
            }
        }
}
