//
//  TableReader.cpp
//  A03
//
//  Created by Andrea Padula on 2/25/17.
//
//

#include "TableReader.h"

void TableReader::read_data(std::string& filename){
        ofFile file;
        file.open(ofToDataPath(filename), ofFile::ReadWrite, false);
        string temp;
        int countLine=0;
        countAtt=0;
        std::vector<string>  t;
        while(getline(file, temp)) {//store the contents of the file in a vector of int
            istringstream iss(temp);
            string token;
            while(std::getline(iss, token, '\t')){
                if(countLine==0){
                    t.push_back(token);
                    countAtt++;
                }
                else{
                    float f=stof((token).c_str(),0);
                    columnValue.push_back(f);
                }
            }

            
            countLine=countLine+1;
                //cout << token << " : newline" << endl;
        }
    columnName=t;
        return;
}


std::vector<float> TableReader::get_column(int which_column){
    if(which_column>countAtt){
        cout<<"error"<<endl;
    }
    std::vector<float> temp;
    
    for (int i=which_column-1; i< columnValue.size(); i=i+countAtt) {
        temp.push_back(columnValue[i]);
        
    }
    return temp;
}
std::string TableReader::get_column_name(int which_column){
    return columnName[which_column-1];

}
int TableReader::getAttributesize(){
    return countAtt;

}
