//
//  SM_BOJ15662_톱니바퀴2.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/11.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

//기준 톱니를 중심으로 왼쪽, 오른쪽 탐색하면서 돌려야하는 톱니바퀴들 큐에 넣음.
//탐색 끝나고 큐에 있는 톱니들 한번에 갱신(회전) 해야 서로 영향 안줌.
//톱니 하나씩 돌리면 N,S극 계속 바뀌어서 기존 톱니 상태 바뀌어버림

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> arrT[1001];
int arrK[1001][2];

void turnRight(int idx){    //idx번째 톱니바퀴 시계방향으로 회전
    
    vector<int> vec = arrT[idx];
    int last = vec[7];
    for(int i=7; i>0; i--){
        vec[i] = vec[i-1];
    }
    vec[0] = last;
    arrT[idx].clear();
    arrT[idx] = vec;
    
}

void turnLeft(int idx){       //idx번째 톱니바퀴 반시계 방향으로 회전
    
    vector<int> vec = arrT[idx];
    int first = vec[0];
    
    for(int i = 0; i<7; i++){
        vec[i] = vec[i+1];
    }
    vec[7] = first;
    
    arrT[idx].clear();
    arrT[idx] = vec;
}

int main(){
    
    int T; cin>>T;
    for(int i = 1; i<=T; i++){
        vector<int> vec;
        for(int j = 0; j<8; j++){
            int n;
            scanf("%1d", &n);
            vec.push_back(n);
        }
        arrT[i] = vec;
    }
    
    int K; cin >> K;
    for(int i = 0; i<K; i++){
        for(int j=0; j<2; j++){
            cin >> arrK[i][j];
        }
        
    }

    queue<pair<int,int>> que;    //회전시켜야하는 톱니바퀴 push
    
    for(int i = 0; i<K; i++){
        
        int center = arrK[i][0];
        int turn = arrK[i][1];

        que.push(make_pair(center,turn));    //기준 톱니바퀴
        
        int right = T - arrK[i][0];     //오른쪽으로 탐색해야하는 톱니바퀴 개수
        int left = T-right-1;           //왼쪽으로 탐색해야하는 톱니바퀴 개수
        
        //1. 오른쪽 탐색
        for(int j = 1; j<=right; j++){
            
            if(arrT[center][2] != arrT[center+1][6]){   //달라서 회전해야할 경우
                turn*=-1;
                que.push(make_pair(center+1, turn));
            }
            else break;
            center++;
        }
        center = arrK[i][0];
        turn = arrK[i][1];
        
        //2. 왼쪽 탐색
        for(int j = 1; j<=left; j++){
            
            if(arrT[center][6] != arrT[center-1][2]){   //달라서 회전해야할 경우
                turn*=-1;
                que.push(make_pair(center-1, turn));
            }
            else break;
            center--;
        }

        while(!que.empty()){
            
            if(que.front().second==1) turnRight(que.front().first);
            else turnLeft(que.front().first);
            
            que.pop();
        }

    }
    

    int ans=0;
    for(int i = 1; i<=T; i++){
        if(arrT[i][0]==1) ans++;
    }
    
    cout << ans;
    
    return 0;
}
