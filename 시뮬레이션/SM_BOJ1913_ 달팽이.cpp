//
//  SM_BOJ1913_ 달팽이.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/01.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//


#include <iostream>
#include <utility>

using namespace std;

//오 아 왼 위
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

int map[1000][1000];
int main(){
    
    pair<int,int> p;
    
    int N, x;
    cin >> N >> x;
    
    int rotateCnt = N/2;        //회오리 수
        
    int num = 1;
    map[N/2][N/2] = num;
    
    int startR = N/2 -1;
    int startC = N/2 -1;
    for(int i = 1; i<=rotateCnt; i++){
        
        int r = startR;
        int c = startC;
        
        for(int d = 0; d<4;){
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if((N/2 -i<=nr && nr<=N/2+i) && (N/2 -i<=nc && nc<=N/2+i)){
                num+=1;
                map[nr][nc] = num;
                if(num==x){
                    p.first = nr + 1;
                    p.second = nc + 1;
                }
                r = nr;
                c = nc;
            }
            else{   //범위 넘어갔으니 방향 바꿔야함
                d++;
            }
           
        }
          
        //시작점 바꾸기 -1, -1
        startR -= 1;
        startC -= 1;
        
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << map[i][j] << " ";
        }cout << endl;
    }
    cout << p.first << " " << p.second ;
    
    
    
    return 0;
}


