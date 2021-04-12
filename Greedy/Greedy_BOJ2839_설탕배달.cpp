//
//  Greedy_BOJ2839_설탕배달.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/12.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>

using namespace std;


int main(){
    
    int N; cin >> N;
    int answer = 0;
    int num = N;
    bool chk = false;
    if(N%5==0){
        answer = N/5;
    }
    else{
        int q = N/5;
        
        while(q>=0){
            num = N-5*q;
            if(num%3==0){
                answer = q + num/3;
                chk = true;
                break;
            }
            else{
                q-=1;
                
            }
        }
        if(!chk){
            if(num%3==0) answer = num/3;
            else answer = -1;
        }
       
    }
    
    
    cout << answer;
    
    return 0;
}
