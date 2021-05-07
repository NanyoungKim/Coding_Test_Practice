//
//  문자열_BOJ1181_ 단어정렬.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/07.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> strVec;
bool cmp(string str1, string str2){
    if(str1.length() == str2.length()){ //길이 같으면 사전순
        return str1.compare(str2) < 0;  //str1이 str2보다 사전순으로 앞
    }
    else{
        return str1.length() < str2.length();   //길이가 짧은 것 부터
    }
}
int main(){
    
    
    int N; cin >> N;
    for(int i = 0; i<N; i++){
        string str;
        cin >> str;
        if(find(strVec.begin(), strVec.end(), str) != strVec.end()) continue;
        strVec.push_back(str);
    }
    sort(strVec.begin(), strVec.end(), cmp);
        
    for(int i = 0; i<strVec.size(); i++){
        cout << strVec[i] << "\n";
    }
    
    
    return 0;
}
