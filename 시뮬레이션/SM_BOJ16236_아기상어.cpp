//
//  SM_BOJ16236_아기상어.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/25.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

//fishVec에 거리, 행, 열 정보 담아서 sort함수 이용해 정렬하면 자동으로 우선순위 적용됨
//물고기 한 마리 먹을 때마다 현재 위치에서 BFS함수 돌려서 먹을 수 있는 물고기들 fishVec에 넣고 sort 후 가장 앞의 물고기 먹고 위치 조정
//fishVec에 물고기 없으면 종료
//맨 처음 아기상어의 위치 저장 후 해당 칸 0으로 설정해서 빈칸으로 바꿔줘야함. (아기상어의 현재 위치 바뀌므로)

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int map[20][20];

//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};


int nowR, nowC;
int babySize = 2;
int toEat = 2;
int resSec = 0;

vector<pair<pair<int,int>,int>> fishVec;        //거리, 가장 위쪽, 가장 왼쪽


void BFS(int row, int col){ //현재 위치에서 먹을 수 있는 물고기까지의 거리와 위치 저장
    
    fishVec.clear();                //현재 위치 바뀌었으므로, 벡터 비운 후 바뀐 현재위치 중심으로 가장 가까운 물고기들 push
    queue<pair<int,int>> que;
    que.push(make_pair(row,col));       //다음에 어디 방문할지 저장하는 큐
    
    int fromStart[20][20] = {0};
    int visited[20][20] = {0};
    visited[row][col] = 1;      //현재 위치는 이미 방문함
    
    int minDist = 1000;
    
    while(!que.empty()){
        
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr<0 || nr>=N || nc<0 || nc>=N || visited[nr][nc]==1 || babySize<map[nr][nc]) continue;  //범위 넘어가거나, 방문했거나, 크기 크면 못 지나감
            
            fromStart[nr][nc] = fromStart[r][c] + 1;
            visited[nr][nc] = 1;
            que.push(make_pair(nr,nc));
            
            if(map[nr][nc]>0 && babySize>map[nr][nc]){  //먹을 수 있는 물고기 (작은거)
                
                //먹을 수 있는 물고기 중 가장 가까운 물고기 먹기
                if(minDist>=fromStart[nr][nc]){
                    minDist = fromStart[nr][nc];
                    fishVec.push_back(make_pair(make_pair(minDist, nr),nc));
                    
                   // cout << nr << " " << nc << "  거리 : " << minDist << "\n";
                }
            }
        }
    }
}


int main(){
    

    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {
                map[i][j] = 0;
                nowR = i; nowC = j;}    //아기상어 위치 저장
        }
    }
    
    
    while(1){
        
        
        BFS(nowR, nowC);            //현재 위치에서 가장 가까운 물고기들 탐색
        if(fishVec.size()==0){      //먹을 수 있는 물고기 없을 때까지
            
            break;
        }
        else{
            
            sort(fishVec.begin(), fishVec.end());   //거리 같은 물고기들 중 위/ 왼 우선순위 적용해서 정렬 후 가장 앞의 요소 먹기
            
            resSec += fishVec[0].first.first;       //이동거리 = 걸린 초
            
            
            //잡아 먹음
            toEat-=1;
            if(toEat==0){
                babySize+=1;
                toEat = babySize;
            }
            
            
            //잡아먹었으니 아기상어 위치 바뀜
            nowR = fishVec[0].first.second;
            nowC = fishVec[0].second;
            
            map[nowR][nowC] = 0;        //해당 칸 물고기 없어져서 빈칸됨
            
        }
    }
    cout <<resSec;
    
    
    
    return 0;
}



