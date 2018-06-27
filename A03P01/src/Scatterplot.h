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
    int maxX,maxY,minY,minX;
    int width, height, x, y;
    vector<float> x_data;
    vector<float> y_data;
    std::string name1, name2;
    ofColor color=ofColor::white;
    ofTrueTypeFont myFont;
    
};
