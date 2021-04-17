//
//  SM_BOJ17144_미세먼지안녕!.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/17.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int R,C,T;
int A[51][51];
//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
queue<pair<int,int>> dustQue;   //미세먼지 있는 칸의 행과 열

vector<int> cleaner;

vector<pair<pair<int,int>,int>> tmpVec[51][51];

void upCleaner(){   //위쪽 공기청정기는 반시계방향
    int upCleanRow = cleaner[0];    //3
    
    for(int r = upCleanRow-1; r>1; r--){    //아래 방향
        A[r][1] = A[r-1][1];
    }
    for(int c = 1; c<C; c++){
        A[1][c] = A[1][c+1];
    }
    for(int r = 1; r<upCleanRow; r++){      //위쪽 방향
        A[r][C] = A[r+1][C];
    }
    for(int c = C; c>=3; c--){
        A[upCleanRow][c] = A[upCleanRow][c-1];
    }
    A[upCleanRow][2] = 0;
}
void downCleaner(){ //아래 쪽 공기청정기는 시계 방향
    int downCleanRow = cleaner[1];  //4
    for(int r = downCleanRow+1; r<R; r++){
        A[r][1] = A[r+1][1];
    }
    for(int c = 1; c<C; c++){
        A[R][c] = A[R][c+1];
    }
    for(int r =R; r>downCleanRow; r--){
        A[r][C] = A[r-1][C];
    }
    for(int c = C; c>=3; c--){
        A[downCleanRow][c] = A[downCleanRow][c-1];
    }
    A[downCleanRow][2] = 0;
}



void chkDustLoc(){
    for(int i = 1; i<=R; i++){
        for(int j=1 ;j<=C; j++){
            if(A[i][j]>0) dustQue.push(make_pair(i,j));
        }
    }
}

void calcDust(){
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            if(tmpVec[i][j].size()!=0){
                for(int k = 0; k<tmpVec[i][j].size(); k++){
                    int nr = tmpVec[i][j][k].first.first;
                    int nc = tmpVec[i][j][k].first.second;
                    int dust = tmpVec[i][j][k].second;
                    A[nr][nc] += dust;
                }
                tmpVec[i][j].clear();
            }
        }
    }
    
}

void spread(){
    int s = dustQue.size();
    //while(!dustQue.empty()){
    for(int i = 0; i<s; i++){
        int r = dustQue.front().first;
        int c = dustQue.front().second;
        dustQue.pop();
        int spreadDust = A[r][c]/5;     //네 방향으로 확산되는 미세먼지 양
        if(spreadDust==0) continue;     //뿌릴 먼지 없으면 스킵
        for(int j = 0; j<4; j++){
            int nr = r + dr[j];
            int nc = c + dc[j];
            
            if(nr<1 || nr>R || nc<1 || nc>C || A[nr][nc]==-1) continue;   //범위 넘거나 공기청정기 있으면 스킵
            
            pair<int,int> p = make_pair(nr, nc);
            tmpVec[r][c].push_back(make_pair(p, spreadDust));
            
        }
        A[r][c] -= spreadDust * tmpVec[r][c].size();
    }
    
    calcDust();         //먼지 확산시키기
   
}


int main(){
    
    scanf("%d%d%d", &R,&C,&T);
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j]==-1){
                cleaner.push_back(i);
            }
            else if(A[i][j]>0){
                dustQue.push(make_pair(i,j));
            }
        }
    }
    
    
    for(int t = 0; t<T; t++){   // 총 T초 동작
        
        //스텝 1. 미세먼지 확산
        spread();
        
        //스텝 2. 공기청정기 작동
        upCleaner();
        downCleaner();
        
        chkDustLoc();       //먼지 위치 파악하기
           
    }
    
    int ans = 0;
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            if(A[i][j]>0) ans+=A[i][j];
        }
    }
    
    cout << ans;
    return 0;
}
