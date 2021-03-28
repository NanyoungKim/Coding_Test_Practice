//
//  BFS_프로그래머스_가장먼노드.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/28.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int visited[20001] = {0};

queue<pair<int,int>> que;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> vecArr[50000];                    //벡터 배열
    
    int v1, v2;
    for(int i = 0; i<edge.size(); i++){            //양방향 엣지 연결
        v1 = edge[i][0];
        v2 = edge[i][1];
        vecArr[v1].push_back(v2);
        vecArr[v2].push_back(v1);
    }
    visited[1] = 1;
    que.push(make_pair(1,0));
    int cnt = 0;
    
    while(!que.empty()){
        
        pair<int,int> p = que.front();
        if(answer == p.second) cnt++;        //가장 먼 노드들의 개수 몇개인지 카운트
        else{                                //depth 증가해서 바뀌면 값 재설정
            answer = p.second;
            cnt = 1;
        }
        que.pop();
        vector<int> vec = vecArr[p.first];
        for(int i = 0; i<vec.size(); i++){
            if(visited[vec[i]]==0){
                visited[vec[i]] = 1;
                que.push(make_pair(vec[i], p.second+1));
            }
        }
        
    }
    answer = cnt;
    
    return answer;
}
