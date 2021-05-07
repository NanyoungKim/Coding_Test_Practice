//
//  Greedy_BOJ13305_주유소.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/07.   11:01 ~ 11:35
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    long long ans = 0;
    
    int N; cin >> N;
    
    vector<long long>  disVec;
    vector<long long> costVec;
    for(int i=0; i<N-1; i++){
        long long d; cin>>d;
        disVec.push_back(d);
    }
    for(int i=0; i<N; i++){
        long long c; cin>>c;
        costVec.push_back(c);
    }
    
    long long greedyMin = 1000000000; //리터당 가격의 최대값
    for(int i = 0; i<N; i++){
        if(costVec[i] < greedyMin){     //더 싼 가격이 나타나서
            greedyMin = costVec[i];     //최소값 갱신
        }
        ans += (disVec[i] * greedyMin); //거리와 최소 가격 곱함
        
    }
    
    cout << ans;

    return 0;
}
