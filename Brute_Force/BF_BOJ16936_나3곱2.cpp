//  BF_BOJ16936_나3곱2.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/03.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<long long> vecB;
vector<long long> vecA;
int N;


void DFS(long long x, int cnt){

    if(cnt==N){
        for(int i = 0; i<N; i++){
            cout << vecA[i] << " ";
        }
        exit(0);
    }
    

    if(x%3==0 && find(vecB.begin(), vecB.end(), x/3)!=vecB.end()){
        vecA.push_back(x/3);
        DFS(x/3, cnt+1);
        vecA.pop_back();
    }
    if(find(vecB.begin(), vecB.end(), 2*x)!=vecB.end()){
        vecA.push_back(2*x);
        DFS(2*x, cnt+1);
        vecA.pop_back();
    }
    return;
}


int main(){

    cin>>N;
   
    long long num;
    for(int i = 0; i<N; i++){
        scanf("%lld", &num);
        vecB.push_back(num);
    }
    
    for(int i = 0; i<vecB.size(); i++){
       
        vecA.push_back(vecB[i]);
        DFS(vecB[i], 1);
        vecA.pop_back();
            
    }
    
    return 0;
}

