//
//  SM_BOJ16236_아기상어.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/25.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <queue>

#include <utility>
using namespace std;

int N;
int map[20][20];

//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

//queue<pair<int,int>> que;
//priority_queue<pair<int, pair<int,int>>> que;           //(물고기 크기, (row,col))

int nowR, nowC;
int babySize = 2;
int toEat = 2;
int resSec = 0;

int onlyOneR, onlyOneC;

int smallerCnt(){
    int res = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if((1<=map[i][j] && map[i][j]<=6) && map[i][j]<babySize){       //물고기 있고 아기상어보다 크기 작으면
                res++;
                onlyOneR = i;
                onlyOneC = j;
            }
            if(res>=2) return res;
        }
    }
    
    return res;
}


int distanceFunc(int startR, int startC, int destR, int destC){
    
    queue<pair<int, int>> disQue;
    disQue.push(make_pair(startR, startC));
    
    int ans=0;
    int fromStart[20][20] = {0};
    int visit[20][20] = {0};
    fromStart[startR][startC] = 0;
    visit[startR][startC] = 1;
    
    while(!disQue.empty()){
        
        int r = disQue.front().first;
        int c = disQue.front().second;
        disQue.pop();
        
        
        if(r==destR && c==destC){
            ans = fromStart[r][c];
            break;
        }
        
        for(int i = 0; i<4; i++){
            
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr>=N || nc<0 || nc>=N || visit[nr][nc]==1 || babySize<map[nr][nc]) continue;    //범위 벗어나거나 이미 방문했거나 크기 크면 못 지나감
            
            fromStart[nr][nc] = fromStart[r][c] + 1;
            disQue.push(make_pair(nr,nc));
            visit[nr][nc] = 1;
            
            
        }
    }
    return ans;
    
}



int distFish[20][20] = {0};
int visited[20][20]= {0};

void func(int row, int col){
    
    queue<pair<int,int>> q;
    q.push(make_pair(row,col));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            distFish[i][j]  = 0; visited[i][j] = 0;
        }
    }
    visited[row][col] = 1;
    distFish[row][col] = 0;
    
    
    while(!q.empty()){
        
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            //범위 벗어나거나                          방문했거나              물고긴데 아기상어보다 커서 못지나가면
            if(nr<0 || nr>=N || nc<0 || nc>=N || visited[nr][nc]==1 || (map[nr][nc]!=9 && babySize<map[nr][nc]) ) continue;
            
            
            q.push(make_pair(nr,nc));
            visited[nr][nc] = 1;
            distFish[nr][nc] = distFish[r][c] + 1;
            
            
        }
    }
}

void chk(){
    for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      printf("%d ", distFish[i][j]);
                  }printf("\n");
               }
               printf("\n\n\n");
}


int main(){
    

    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {nowR = i; nowC = j;}    //아기상어 위치 저장
        }
    }
    
    
    while(1){    //먹을 수 있는 물고기 없을 때까지
        
       
        //물고기 한 마리 먹을 때마다 자기보다 작은 물고기 검사
        int smallerFish = smallerCnt();
        

        //작은 물고기 없어서 더이상 머글 수 있는 물고기 x -> 도움 요청
        if(smallerFish==0){
            break;
        }
        
        //먹을 수 있는 물고기 1개
        else if(smallerFish==1){
            int disToDest = distanceFunc(nowR, nowC, onlyOneR, onlyOneC);   //이동하는데 걸리는 시간
            resSec += disToDest;
            
            
            
            map[onlyOneR][onlyOneC] = 0;        //물고기 잡아먹었으니 빈칸됨
            
            nowR = onlyOneR;        //아기상어 위치 바뀜
            nowC = onlyOneC;
            
            toEat-=1;
            if(toEat==0){
                babySize+=1;
                toEat = babySize;
            }
            
        }
 
        //2개이상이면 거리들 비교해서 가장 가깝고 + 위 + 왼
        else{
            
            func(nowR,nowC);
            chk();
            int minDist = 1000; int minR=-1, minC = -1;
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(map[i][j]<babySize && distFish[i][j]!=0 && (1<=map[i][j] && map[i][j]<=6)){        //아기상어보다 큰 물고기가 아니고 &&
                        if(minDist>distFish[i][j]){
                            minDist = distFish[i][j];
                            minR = i; minC = j;
                        }
                    }

                }
            }
            
            cout << "mini : " << minR << " " << minC << "\n";
            //int disToDest = distanceFunc(nowR, nowC, minR, minC);   //이동하는데 걸리는 시간
            //resSec += disToDest;
            resSec += distFish[minR][minC];
            
            
            map[minR][minC] = 0;        //물고기 잡아먹었으니 빈칸됨
            
            nowR = minR;        //아기상어 위치 바뀜
            nowC = minC;
            
            toEat-=1;
            if(toEat==0){
                babySize+=1;
                toEat = babySize;
            }
            
        }
        
    }
    
    
    
    
    cout <<resSec;
    
    
    
    return 0;
}



