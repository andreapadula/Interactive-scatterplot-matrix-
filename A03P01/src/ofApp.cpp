#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    table.read_data(s);
    std::vector<float> temp=table.get_column(c);
    std::vector<float> temp2=table.get_column(c2);
    table.get_column_name(1);
    table.get_column_name(2);
    plot.setup(temp, temp2, 500, 500, 80, 80, table.get_column_name(c), table.get_column_name(c2));
    
//    
//    for (int i=0; i< temp.size(); i=i+1) {
//        std::cout<<temp[i]<<endl;
//        
//    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    //ofPopStyle();
    plot.draw();
//    ofDrawBitmapString("Hello World!", 600, 600);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        string str;
        cout<<"enter name between Iris,Auto-mpg,Abalone,Wine Quality"<<endl;
        cin>>str;
        setFileName(str);
        table.read_data(s);
        cout<<"Choose 2 column number between :"<<endl;
        size=table.getAttributesize();
        for (int i=0; i< size; i++) {
            cout<<table.get_column_name(i+1)<<", ";
        }
        cout<<endl;
        cout<<"Please enter ONE number between:"<<1<<" and "<<size<<endl;
        cin>>c;
        cout<<"Please enter ONE number between:"<<1<<" and "<<size<<endl;
        cin>>c2;
        std::vector<float> temp=table.get_column(c);
        std::vector<float> temp2=table.get_column(c2);
        plot.setup(temp, temp2, 500, 500, 80, 80, table.get_column_name(c), table.get_column_name(c2));
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
