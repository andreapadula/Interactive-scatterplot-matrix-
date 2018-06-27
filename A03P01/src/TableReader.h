//
//  TableReader.hpp
//  A03
//
//  Created by Andrea Padula on 2/25/17.
//
//

#pragma once

#include "ofMain.h"

class TableReader {

public:
    void read_data(std::string& filename);
    //int numOfColum=10;
    //int static numOfColum;
    int countAtt=0;
    std::vector<string>  columnName;
    std::vector<float> columnValue;
    std::vector<float> get_column(int which_column);
    std::string get_column_name(int which_column);
    int getAttributesize();
};
