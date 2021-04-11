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


int searchDisBFS(){
    
    memset(newMap, 0, sizeof(newMap));

    for(int i = 0; i<pickedChick.size(); i++){
        int r = pickedChick[i].first;
        int c = pickedChick[i].second;
        newMap[r][c] = 2;
    }
    
    int sum=0;
    for(int i = 0; i<homeVec.size(); i++){
        memset(fromStart, 0, sizeof(fromStart));
        queue<pair<int,int>> que;
        que.push(make_pair(homeVec[i].first, homeVec[i].second));
        int initR = que.front().first;
        int initC = que.front().second;

        
        while(!que.empty()){
             
            
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            
            if(newMap[r][c] == 2){
                sum+=fromStart[r][c];
                break;
            }
            
            for(int j = 0; j<4; j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr<1 || nr>N ||nc<1 || nc>N || fromStart[nr][nc]!=0 || (nr==initR && nc==initC)) continue;
              
                que.push(make_pair(nr,nc));
                fromStart[nr][nc] = fromStart[r][c] + 1;
                
            }
           
            
        }
       
    }
    
    return sum;
}


void pickChickDFS(int toPick){

    if(toPick==0){
        int disSum = searchDisBFS();
        if(mini>disSum) mini = disSum;
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
    cout << mini;
    
    return 0;
}
