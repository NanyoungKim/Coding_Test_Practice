//
//  Programmers_SummerCoding_1.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/09.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class Data{
  
public:
    

};

vector<pair<string,string>> vec;
vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;
    

    
    for(int i = 0; i<data.size(); i++){
        string str = data[i];
        istringstream ss(str);
        string stringBuffer;
        vector<string> splitStr;
        splitStr.clear();
        
        while (getline(ss, stringBuffer, ' ')){
            splitStr.push_back(stringBuffer);
            cout<<stringBuffer<<" ";
        }
        
        string co="";
        co.append(splitStr[1][5], 6);
        string ti="";
        ti.append(splitStr[2][5], 8);
        string pr="";
        int priLen = splitStr[0].length();
        pr.append(splitStr[0][6], priLen-6);
        if(code==co && day==ti){
            vec.push_back(make_pair(splitStr[2], pr));
        }
        
    }
    
    sort(vec.begin(), vec.end());
    for(int i = 0; i<vec.size(); i++){
        answer.push_back(stoi(vec[i].second));
    }
    
    
    
    
    return answer;
}
