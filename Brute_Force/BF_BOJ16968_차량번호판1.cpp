//
//  BF_BOJ16968_차량번호판1.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/03.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//
//완전탐색
//이전과 형식 연속되는지만 체크해서 연속되면 해당 글자와 겹치지 않게 1 감소시켜서 곱하기

#include <iostream>
#include <string>

using namespace std;


int main(){
    
    string type;
    cin >> type;
    int answer = 1;
    
    int numD = 10;      //0~9
    int numC = 26;      //a~z
    
    if(type[0]=='c') answer = numC;
    else answer = numD;
    
    for(int i = 1; i<type.length(); i++){       //이전 형식과 연속되는지 검사
        
        if(type[i]=='c'){
            
            if(type[i-1]=='c'){ //연속된 경우 cc
                answer *= (numC-1);
            }
            else{   //dc
                answer *= numC;
            }
        }
            
        else{
            
            if(type[i-1]=='c'){ //cd
                answer *= numD;
            }
            else{   //연속된 경우 dd
                answer *= (numD-1);
            }
        }
        
    }
    
    cout << answer;
    
    
    
    
    return 0;
}
