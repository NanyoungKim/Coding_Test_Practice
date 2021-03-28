//
//  BFS_프로그래머스_순위.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/28.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

int cntArr[101] = {0};


int BFS(int init, vector<int>* vecArrWin, vector<int>* vecArrLose){
    queue<int> que;
    que.push(init);
    int cnt = 0;
    int visited[101] = {0};
    visited[init] = 1;
    while(!que.empty()){
        
        int startNode = que.front();
        que.pop();
        
        for(int i = 0; i<vecArrWin[startNode].size(); i++){    //i가 승리자 -> i에게 진 사람들 카운트
            if(visited[vecArrWin[startNode][i]] == 0){
                visited[vecArrWin[startNode][i]] = 1;
                que.push(vecArrWin[startNode][i]);
                cnt++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    que.push(init);
    visited[init] = 1;
    while(!que.empty()){
        int startNode = que.front();
        que.pop();
        
        for(int i = 0; i<vecArrLose[startNode].size(); i++){ //i가 패배자 -> i가 이긴 사람들 카운트
            if(visited[vecArrLose[startNode][i]] == 0){
                visited[vecArrLose[startNode][i]] = 1;
                que.push(vecArrLose[startNode][i]);
                cnt++;
            }
        }
    }
    cout << endl;
    return cnt;
    
}



int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<int> vecArrWin[101];
    vector<int> vecArrLose[101];
    
    int winner, loser;
    for(int i = 0; i<results.size(); i++){
        winner = results[i][0];
        loser = results[i][1];
        
        vecArrWin[winner].push_back(loser);
        vecArrLose[loser].push_back(winner);
    }
    for(int i = 1; i<=n; i++){
        if(n-1 == BFS(i, vecArrWin, vecArrLose)){        //자신을 제외한 n-1명과 승/패 관계 알아야 함
            answer++;
        }
    }
    return answer;
}
