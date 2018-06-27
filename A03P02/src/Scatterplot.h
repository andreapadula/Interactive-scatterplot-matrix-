//
//  Scatterplot.hpp
//  A03
//
//  Created by Andrea Padula on 2/25/17.
//
//
#pragma once

#include "ofMain.h"

class Scatterplot {
public:

    void setup(std::vector<float> column1,std::vector<float> column2,int width, int height, int x, int y,std::string name1,std::string name2);
    void draw();
    void setAxis();
    //void updateAxis();
    void setValue();
    void mouseMoved(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);
    void mouseEntered(ofMouseEventArgs & args);
    void mouseExited(ofMouseEventArgs & args);
    
    //this function checks if the passed arguments are inside the Canvas.
    bool inside(float _x, float _y );
    bool onPoint(float x, float y );
    ofEvent<ofVec2f> clickedInside;
    int ratio=10;
    int maxX,maxY,minY,minX;
    int ZmaxX,ZmaxY,ZminY,ZminX;
    int width, height, x, y;
    vector<float> tranX;
    vector<float> tranY;
    vector<float> x_data;
    vector<float> y_data;
    vector<float> x_zoom;
    vector<float> y_zoom;
    vector<float> x_zoom2;
    vector<float> y_zoom2;
    std::string name1, name2;
    ofColor color=ofColor::white;
    ofTrueTypeFont myFont;
    ofTrueTypeFont myFont2;
    std::vector<bool> section;
    bool selected, zoom,view;
    int index;
    int sx0, sy0,sx1,sy1,sx2,sy2,sx3,sy3;
protected:
    bool bRegisteredEvents;
};
