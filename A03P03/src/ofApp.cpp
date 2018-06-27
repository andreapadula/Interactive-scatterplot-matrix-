#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    TableReader table;
    insert(table);



}
void ofApp::insert(TableReader table){
    table.read_data(s);
    std::vector<float> temp;//=table.get_column(c);
    std::vector<float> temp2;
    int att=table.getAttributesize();
    for (int i =1; i<=att; i++) {
        combination.push_back(i);
    }
    comb(combination.size(), 2, combination, 2);
    int t=0;
    int t2=0;
    
    int size=combination2.size();
    int width, height,space, increment;
    int limit,limit2;
    space=80;
    if((size/2)<=9){
        width=300;
        height=300;
        increment=400;
        limit=5;
        limit2=3;
    }
    else if((size/2)<=30){
        width=150;
        height=150;
        increment=200;
        limit=7;
        limit2=7;
    }
    else if((size/2)>=31){
        width=80;
        height=80;
        increment=150;
        limit=15;
        limit2=10;
    }
    
    int tot=0;
    
    myplot = new vector<Scatterplot>(size);
    for (int rows=0; rows<limit; rows++) {
        Scatterplot plot=*new Scatterplot();
        myplot->push_back(plot);
        temp=table.get_column(combination2[tot]);
        temp2=table.get_column(combination2[tot+1]);
        myplot->at(tot).setup(temp, temp2, width, height, space+t, space+t2, table.get_column_name(combination2[tot]), table.get_column_name(combination2[tot+1]));
        ofAddListener(myplot->at(tot).brushedSelection,this,&ofApp::onMouseInCanvas);
        tot=tot+2;
        for (int cols=0; cols<limit2; cols++) {
            t=t+increment;
            Scatterplot plot2=*new Scatterplot();
            myplot->push_back(plot2);
            temp=table.get_column(combination2[tot]);
            temp2=table.get_column(combination2[tot+1]);
            myplot->at(tot).setup(temp, temp2, width, height, space+t, space+t2, table.get_column_name(combination2[tot]), table.get_column_name(combination2[tot+1]));
            ofAddListener(myplot->at(tot).brushedSelection,this,&ofApp::onMouseInCanvas);
            tot=tot+2;
            if((tot)==size)
                break;
            //break;
        }
        t=0;
        t2=t2+increment;
        if((tot)==size)
            break;
        //break;
    }


}
void ofApp::comb(int n, int r,vector<int> arr, int sz) {
    for (int i = n; i >= r; i --) {
        
        arr[r - 1] = i;
        if (r > 1) {
            comb(i - 1, r - 1, arr, sz);
        } else {
            for (int i = 0; i < sz; i ++) {
                combination2.push_back(arr[i]);
            }
        }
    }
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    for (int i=0; i<myplot->size(); i++) {
        myplot->at(i).draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        string str;
        cout<<"enter name between Iris,Auto-mpg,Abalone,Wine Quality"<<endl;
        cin>>str;
        setFileName(str);
        myplot->clear();
        combination2.clear();
        combination.clear();
        TableReader table;
        insert(table);
    }
    
}
void ofApp::setFileName(string str){
        if(str.compare("Iris")==0)
            s="config.tsv";
        else if (str.compare("Auto-mpg")==0)
            s="auto-mpg.tsv";
        else if (str.compare("Abalone")==0)
            s="abalone.tsv";
        else if (str.compare("Wine Quality")==0)
            s="winequality-white.tsv";

}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::onMouseInCanvas(vector<bool> & e){

    for (int i=0; i<myplot->size(); i++) {
        myplot->at(i).section = e;
    }
}
