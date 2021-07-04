//
//  문자열_BOJ4949_균형잡힌세상.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/07/04.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool chkPair(char c1, char c2){
    if(c1=='(' && c2==')') return 1;
    if(c1=='[' && c2==']') return 1;
    return 0;
}

int main(){
    string str = "";
    
    while(true){
        getline(cin, str);
        if(str.length()==1 && str[0] == '.') break;
        
        stack<char> stk;
        bool flag = true;
        
        for(int i = 0; i<str.length(); i++){
            if(str[i] == '(' || str[i] == '[') {
                stk.push(str[i]);
            }
            if(str[i] == ')' || str[i] == ']') {
                
                if(stk.empty()){            //1. 아무것도 없는데 닫는 괄호면
                    flag = false;
                    break;
                }
                else{           //2. 스택에 열린 괄호 들어 있을 때,
                    //2-1. 짝 맞으면
                    if(chkPair(stk.top(), str[i])) stk.pop();
                    //2-2. 짝 안 맞으면
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(!flag) cout << "no\n";
        else{
            if(stk.empty()) {cout << "yes\n"; continue;}
            else cout << "no\n";
        }
    }
    
    return 0;
}
