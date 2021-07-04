//
//  문자열_BOJ1032_명령프롬프트.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/07/04.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
    
    int N; cin >> N;
    string str="";
    
    char arr[50];
    
    cin >> str;
    
    for(int i = 0; i<str.length(); i++)  arr[i] = str[i];
    
    for(int i = 1; i<N; i++){
        cin >> str;
        for(int s = 0; s<str.length(); s++){
            if(arr[s] != str[s]) arr[s] = '?';
        }
    }
    for(int i = 0; i<str.length(); i++) cout << arr[i];
    return 0;
}
