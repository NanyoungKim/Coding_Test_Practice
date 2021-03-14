//
//  SM_BOJ14499_주사위굴리기.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/14.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int map[20][20];
int N, M, x, y, K;
vector<int> vecK;

    //오, 왼, 위, 아
int dr[5] = {0,0,0,-1,1};
int dc[5] = {0,1,-1,0,0};
int dice[6] = {0,0,0,0,0,0};

void east(){    //1(동)
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
}
void west(){    //2(서)
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
}
void south(){   //4(남)
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
    
}
void north(){   //3(북)
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
    
    
}

int main(){
    
    cin >> N >> M >> x >> y >> K;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i = 0; i<K; i++){
        int n; cin >> n;
        vecK.push_back(n);
    }
    
    int r = x;
    int c = y;
    for(int i = 0; i<K; i++){
            
        int nr = r + dr[vecK[i]];
        int nc = c + dc[vecK[i]];
        
        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        
        if(vecK[i]==1){ east(); }        //동
        else if(vecK[i]==2){ west(); }  //서
        else if(vecK[i]==3){ north(); }  //북
        else { south(); }    //남
        
        
        
        if(map[nr][nc]==0){     //이동한 칸에 쓰여 있는 수가 0이면
            //주사위 바닥면에 쓰인 수가 복사됨
            map[nr][nc] = dice[5];
        }
        else{                   //0이 아니면
                //칸에 쓰인 수가 주사위 받가면으로 복사되며 칸의 수는 0이 됨
            dice[5] = map[nr][nc];
            map[nr][nc] = 0;
        }
        
        printf("%d\n", dice[0]);
        
        
        
        r = nr;
        c = nc;
       
        
        
        
    }
    
    
    
    return 0;
}
