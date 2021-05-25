//
//  BFS_BOJ17071_숨바꼭질5.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/25.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;


int visited[2][500001];

bool chk(int loc){
    if(0<=loc && loc <= 500000) return true;
    else return false;
}

int main(){
    
    int N, K;
    cin>> N >> K;


    queue<pair<int,int>> que;
    que.push(make_pair(N,0));
    visited[0][N] = 0;      //첫 시작 위치는 0초만에 도달
    memset(visited, -1, sizeof(visited));

   
    
    while(!que.empty()){
    
        int subinLoc = que.front().first;
        int subinTime = que.front().second;
        que.pop();
          
        if(chk(subinLoc)== false || visited[subinTime%2][subinLoc]!=-1) continue;
        
        visited[subinTime%2][subinLoc] = subinTime; //해당 위치에 최소 몇초만에 도달했는지 저장
        
        
        que.push(make_pair(subinLoc-1, subinTime+1));
        que.push(make_pair(subinLoc+1, subinTime+1));
        que.push(make_pair(subinLoc*2, subinTime+1));
    }
    
    bool flag = false;
    for(int i = 0; i<=500000; i++){
        K += i;
        if(K > 500000) break;
        if(visited[i%2][K] != -1 && visited[i%2][K] <= i) {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
    
    return 0;
}
