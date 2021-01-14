//
//  BFS_BOJ1389_케빈베이컨의6단계법칙.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/01/13.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;
vector<int> connect[101];
queue<int> que;

int BFS(int start){
    
    int fromStart[101] = {0};
    
    while(!que.empty()){
        
        int x = que.front();
        que.pop();
        
        for(int i = 0; i<connect[x].size(); i++){
            
            int next = connect[x][i];
            
            if(fromStart[next]==0 && next!=start){
                fromStart[next] = fromStart[x] + 1;
                que.push(next);
            }
        }
    }
    
    int sum = 0;
    for(int i = 1; i<=N; i++){
        sum += fromStart[i];
    }
    
    return sum;

    
}


int main(){
    
    int answer = 0;
    
    cin >> N >> M;
    
    for(int i = 0; i<M; i++){
        int a,b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    
    
    int min = 50000000;
    for(int i = 1; i<=N; i++){
        que.push(i);
        int res = BFS(i);
        //cout << "i " << "res : " << res << endl;
        
        if(res<min){
            min = res;
            answer = i;
        }
        
    }
    cout << answer;
    
    
    return 0;
}
