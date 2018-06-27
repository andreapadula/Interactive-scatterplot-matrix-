//
//  Scatterplot.cpp
//  A03
//
//  Created by Andrea Padula on 2/25/17.
//
//

#include "Scatterplot.h"

//set up the plot

void Scatterplot::setup(std::vector<float> column1,std::vector<float> column2,int width, int height, int x, int y,std::string name1,std::string name2){
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->name1=name1;
    this->name2=name2;
    this->x_data=column1;
    this->y_data=column2;
    this-> maxX= *max_element(x_data.begin(), x_data.end())+1;
    this-> minX= *min_element(x_data.begin(), x_data.end())-1;
    this-> maxY= *max_element(y_data.begin(), y_data.end())+1;
    this-> minY= *min_element(y_data.begin(), y_data.end())-1;
    myFont.load("verdana.ttf", 10, true, true); //set the font
    
}
//place the names for the axis and the value, draw a grid
void Scatterplot::setAxis(){

    ofPushMatrix();
    ofTranslate(x,y);
    ofSetColor(211,211,211);
    ofSetLineWidth(0.5);
    int space=height/5;
    int space2=height-space;
    float value=(float)maxY/5;
    for (int i=0; i<5; i++) {
        
        stringstream stream;
        string s;
        if(value<999){
            stream << fixed << setprecision(1) << value;
            s = stream.str();}
        else{
            stream << fixed << setprecision(0) << value;
            s = stream.str();
        }
        ofSetColor(211,211,211);
        ofDrawLine(500, space2,0, space2);
        ofSetColor(0,0,0);
        myFont.drawString(s,  -40,space2);
        space2=space2-space;
        value=value+((float)maxY/5);
    }
    ofSetLineWidth(0.5);
    space=width/5;
    space2=space;
    value=(float)maxX/5;
    for (int i=0; i<5; i++) {
        stringstream stream;
        string s;
        if(value<999){
            stream << fixed << setprecision(1) << value;
            s = stream.str();}
        else{
            stream << fixed << setprecision(0) << value;
            s = stream.str();
        }
        ofSetColor(211,211,211);
        ofDrawLine(space2,0,space2, 500);
        ofSetColor(0,0,0);
        myFont.drawString(s, space2-10,width+20);
        space2=space2+space;
        value=value+((float)maxX/5);
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
    myFont.drawString(name2, -250, -55);
    
    ofPopMatrix();

}
//draw the data 
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
    for (int i=0; i<x_data.size(); i++) {
        //cout<<
        int x1=0;
        int y1=0;
        x1 = ofMap(x_data[i], minX, maxX, 0, width);
        y1 = ofMap(y_data[i], minY, maxY, 0, height);

        ofColor color = ofColor::fromHsb(150,x1/2,200);//choose the color
        ofSetColor( color );//set the color
        
        ofDrawCircle(x1,-y1,5);
    }
    ofPopMatrix();
}
