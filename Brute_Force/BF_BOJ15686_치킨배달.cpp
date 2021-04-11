//
//  BF_BOJ15686_치킨배달.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/11.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;

int N, M;

int map[51][51];
int fromStart[51][51];
int newMap[51][51];
vector<pair<int,int>> homeVec;       //1
vector<pair<int,int>> chickenVec;   //2
int visited[100] = {0};
vector<pair<int,int>> pickedChick;   //2중 M개 선택

//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int mini = 100000000;
int answer =100000000;


void pickChickDFS(int toPick){

    if(toPick==0){
        
        int sum=0;
        //각 집에서 pickChick까지의 거리들 중 최소값들의 합
        for(int i = 0; i<homeVec.size();i++){
            mini = 100000000;
            
            for(int j = 0; j<pickedChick.size(); j++){
                int dis = abs(homeVec[i].first-pickedChick[j].first)
                + abs(homeVec[i].second - pickedChick[j].second);
                
                if(mini>dis) mini = dis;
            }
            sum+=mini;
            if(sum>answer) return;
        }
        
        if(answer>sum) answer = sum;
        return;
        
    }
    
    for(int i = 0; i<chickenVec.size(); i++){
        if(visited[i]==0){
            visited[i] = 1;
            pickedChick.push_back(chickenVec[i]);
            pickChickDFS(toPick-1);
            pickedChick.pop_back();
            visited[i] = 0;
        }
    }
    
    
}


int main(){
    cin >> N >> M;
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j]==1){   homeVec.push_back(make_pair(i,j)); }
            if(map[i][j]==2){   chickenVec.push_back(make_pair(i,j)); }
        }
    }
    
    pickChickDFS(M);
    cout << answer;
    
    return 0;
}
