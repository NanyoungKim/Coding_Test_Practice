//
//  문자열_BOJ10953_A+B-6.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/07/04.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    int T; cin >> T;
    string str = "";
    for(int i = 0; i<T; i++){
        cin >> str;
        int a = str[0]-'0';
        int b = str[2]-'0';
        cout << a + b << "\n";
    }
    return 0;
}
