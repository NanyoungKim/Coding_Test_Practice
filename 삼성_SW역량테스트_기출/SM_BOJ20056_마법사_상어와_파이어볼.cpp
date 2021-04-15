//
//  SM_BOJ20056_마법사_상어와_파이어볼.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/05.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

class Ball{
public:

    int r,c,m, s, d;
    Ball();
    Ball(int r, int c, int m, int s, int d){
        this->r = r;
        this->c = c;
        this->m = m;
        this->s = s;
        this->d = d;
    }
};
int N,M,K;
vector<Ball> map[51][51];
vector<Ball> ballVec;
int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};
int dArr[4] = {0};

void initdArr(bool isEorO){
    
    if(isEorO){
        dArr[0] = 0; dArr[1] = 2; dArr[2] = 4; dArr[3] = 6;
    }
    else{
        dArr[0] = 1; dArr[1] = 3; dArr[2] = 5; dArr[3] = 7;
    }
}

bool isAllEorO(int row, int col){       //모두 짝수거나 홀수인지 체크
    
    int evenNum=0;
    for(int i = 0; i<map[row][col].size(); i++){
        Ball fireball = map[row][col][i];
        if(fireball.d%2==0){
            evenNum++;
        }
    }
    if(evenNum==map[row][col].size()) return true;  //모두 짝수이면
    
    int oddNum=0;
    for(int i = 0; i<map[row][col].size(); i++){
           Ball fireball = map[row][col][i];
           if(fireball.d%2==1){
               oddNum++;
           }
    }
    if(oddNum==map[row][col].size()) return true;
    
    return false;
 
}

int modFunc(int x){

    if(x>0){
        x = x%N;
    }
    else{
        while(x<=0){ //x가 0보다 커지면 stop
            x+=N;
        }
    }
    return x;
}

int main(){
    
    
    cin >> N >> M >> K;
    
    for(int i = 1; i<=M; i++){
        int r,c,m,s,d;
        scanf("%d%d%d%d%d", &r, &c, &m, &s, &d);
        map[r][c].push_back(Ball(r,c,m,s,d));
    }
    
    for(int move=0; move<K; move++){
        vector<Ball> tmp;
        //1번 : 모든 파이어볼 자신 방향, 속력 만큼 이동
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(map[i][j].size()==0) continue;
                vector<Ball>::iterator iter;
                for(iter=map[i][j].begin(); iter!=map[i][j].end(); iter++){
                    Ball ball = *iter;
                    int nr = i + dr[ball.d] * ball.s;
                    int nc = j + dc[ball.d] * ball.s;

                    if(nr<1 || nr>N ){
                        nr = modFunc(nr);
                        if(nr==0){nr = N;}
                    }
                    if(nc<1 || nc>N) {
                        nc = modFunc(nc);
                        if(nc==0){nc = N;}
                    }
                    tmp.push_back(Ball(nr,nc,ball.m, ball.s, ball.d));
                    map[i][j].erase(iter);
                    --iter;
                }
               
            }
        }
        for(int i = 0; i<tmp.size(); i++){
            Ball ball = tmp[i];
            map[ball.r][ball.c].push_back(ball);
        }
        
        //2번
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                vector<Ball> tmpBallVec = map[i][j];
                if(tmpBallVec.size()>=2){
                    int sumM=0, sumS=0;
                    bool EorO = isAllEorO(i, j);
                    
                    for(int k=0; k<tmpBallVec.size(); k++){         //그 칸에 있는 볼 개수만큼
                        sumM += map[i][j][k].m;
                        sumS += map[i][j][k].s;
                    }
                    //정리
                    if(sumM/5==0) {
                        map[i][j].clear();      //2. 그 칸에 있던 볼들 클리어
                    }
                    else{
                        map[i][j].clear();
                        initdArr(EorO);
                        for(int f = 0; f<4; f++){       //파이어 볼 4개로 나눠짐
                            map[i][j].push_back(Ball(i,j,sumM/5, sumS/tmpBallVec.size(), dArr[f]));
                        }
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int k = 0; k<map[i][j].size(); k++){
                answer += map[i][j][k].m;
            }
        }
    }
    
    cout << answer;
    
    
    return 0;
}
