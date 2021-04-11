//
//  DP_BOJ2579_계단오르기.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/11.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int stair[300] = {0};
int dp[300] = {0};
vector<pair<int,int>> vecArr[300];

int main(){
    
    int N; cin >> N;
    for(int i = 0; i<N; i++){
        cin >> stair[i];
    }
    
    //dp[0], dp[1] 초기화
    vecArr[0].push_back(make_pair(0,0));            //-1
    vecArr[0].push_back(make_pair(stair[0],1));     //0
    
    dp[0] = stair[0];
    
    vecArr[1].push_back(make_pair(dp[0], 0));               //0 x
    vecArr[1].push_back(make_pair(stair[1], 1));            //x 1
    vecArr[1].push_back(make_pair(stair[0] + stair[1], 2)); //0 1
    
    int maxi=0;
    for(int i = 0; i<3; i++){
        if(maxi<vecArr[1][i].first) maxi = vecArr[1][i].first;
    } dp[1] = maxi;
    
    
    
    for(int i = 2; i<=N-1; i++){
        
        //case 1 : 현재 계단 안 밟는 경우
        if(i!=N-1){     //문제의 조건에서 마지막 계단은 무조건 밟는다고 했음
            vecArr[i].push_back(make_pair(dp[i-1], 0));     //직전 계단까지 왔을 때 최대값
        }
        
        //case 2 : 현재 계단 밟는 경우
        int maxi = 0;
        for(int j = 0; j<vecArr[i-1].size(); j++){
            int conti = vecArr[i-1][j].second;
            if(conti==2) continue;                  //직전 계단까지 2개 연속해서 밟은 경우, 3개 연속 못 밟음
            
            int sum = stair[i] + vecArr[i-1][j].first;
            if(maxi < sum) maxi = sum;
            vecArr[i].push_back(make_pair(sum,conti+1));    //현재 계단 밟았으므로 연속해서 밟은 계단 수 1증가해서 저장
 
        }
        dp[i] = maxi;
        
    }
    cout << dp[N-1];
    
    return 0;
}
