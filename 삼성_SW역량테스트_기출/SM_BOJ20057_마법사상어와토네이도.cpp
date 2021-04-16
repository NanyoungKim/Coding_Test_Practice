//
//  SM_BOJ20057_마법사상어와토네이도.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/15.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>

int A[500][500];
int N;
using namespace std;

//왼 아 오 위
int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};

int sandPercent[6] = {0};
int ansSand = 0;

void moveSand(int r, int c, int d){ //y = A[r][c]
    
    if(d==0){   //왼쪽 이동
        if((1<=r-1 && r-1<=N) && (1<=c+1 && c+1<=N)){
            A[r-1][c+1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r+1 && r+1<=N) && (1<=c+1 && c+1<=N)){
            A[r+1][c+1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r-2 && r-2<=N) && (1<=c && c<=N)){
            A[r-2][c] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r+2 && r+2<=N) && (1<=c && c<=N)){
            A[r+2][c] += sandPercent[1];
        }  else ansSand += sandPercent[1];
        if((1<=r && r<=N) && (1<=c-2 && c-2<=N)){
            A[r][c-2] += sandPercent[2];
        } else ansSand += sandPercent[2];
        if((1<=r-1 && r-1<=N) && (1<=c && c<=N)){
            A[r-1][c] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r+1 && r+1<=N) && (1<=c && c<=N)){
            A[r+1][c] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r-1 && r-1<=N) && (1<=c-1 && c-1<=N)){
            A[r-1][c-1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r+1 && r+1<=N) && (1<=c-1 && c-1<=N)){
            A[r+1][c-1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r && r<=N) && (1<=c-1 && c-1<=N)){
            A[r][c-1] += sandPercent[5];
        } else ansSand += sandPercent[5];
    }
        
    if(d==1){
        if((1<=r-1 && r-1<=N) && (1<=c-1 && c-1<=N)){
            A[r-1][c-1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r-1 && r-1<=N) && (1<=c+1 && c+1<=N)){
            A[r-1][c+1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r && r<=N) && (1<=c-2 && c-2<=N)){
            A[r][c-2] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r && r<=N) && (1<=c+2 && c+2<=N)){
            A[r][c+2] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r+2 && r+2<=N) && (1<=c && c<=N)){
            A[r+2][c] += sandPercent[2];
        } else ansSand += sandPercent[2];
        if((1<=r && r<=N) && (1<=c-1 && c-1<=N)){
            A[r][c-1] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r && r<=N) && (1<=c+1 && c+1<=N)){
            A[r][c+1] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r+1 && r+1<=N) && (1<=c-1 && c-1<=N)){
            A[r+1][c-1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r+1 && r+1<=N) && (1<=c+1 && c+1<=N)){
            A[r+1][c+1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r+1 && r+1<=N) && (1<=c && c<=N)){
            A[r+1][c] += sandPercent[5];
        } else ansSand += sandPercent[5];
    }
    if(d==2){
        if((1<=r-1 && r-1<=N) && (1<=c-1 && c-1<=N)){
            A[r-1][c-1] += sandPercent[0];
        }  else ansSand += sandPercent[0];
        if((1<=r+1 && r+1<=N) && (1<=c-1 && c-1<=N)){
            A[r+1][c-1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r-2 && r-2<=N) && (1<=c && c<=N)){
            A[r-2][c] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r+2 && r+2<=N) && (1<=c && c<=N)){
            A[r+2][c] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r && r<=N) && (1<=c+2 && c+2<=N)){
            A[r][c+2] += sandPercent[2];
        } else ansSand += sandPercent[2];
        if((1<=r-1 && r-1<=N) && (1<=c && c<=N)){
            A[r-1][c] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r+1 && r+1<=N) && (1<=c && c<=N)){
            A[r+1][c] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r-1 && r-1<=N) && (1<=c+1 && c+1<=N)){
            A[r-1][c+1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r+1 && r+1<=N) && (1<=c+1 && c+1<=N)){
            A[r+1][c+1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r && r<=N) && (1<=c+1 && c+1<=N)){
            A[r][c+1] += sandPercent[5];
        } else ansSand += sandPercent[5];
    }
    if(d==3){
        if((1<=r+1 && r+1<=N) && (1<=c-1 && c-1<=N)){
            A[r+1][c-1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r+1 && r+1<=N) && (1<=c+1 && c+1<=N)){
            A[r+1][c+1] += sandPercent[0];
        } else ansSand += sandPercent[0];
        if((1<=r && r<=N) && (1<=c-2 && c-2<=N)){
            A[r][c-2] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r && r<=N) && (1<=c+2 && c+2<=N)){
            A[r][c+2] += sandPercent[1];
        } else ansSand += sandPercent[1];
        if((1<=r-2 && r-2<=N) && (1<=c && c<=N)){
            A[r-2][c] += sandPercent[2];
        } else ansSand += sandPercent[2];
        if((1<=r && r<=N) && (1<=c-1 && c-1<=N)){
            A[r][c-1] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r && r<=N) && (1<=c+1 && c+1<=N)){
            A[r][c+1] += sandPercent[3];
        } else ansSand += sandPercent[3];
        if((1<=r-1 && r-1<=N) && (1<=c-1 && c-1<=N)){
            A[r-1][c-1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r-1 && r-1<=N) && (1<=c+1 && c+1<=N)){
            A[r-1][c+1] += sandPercent[4];
        } else ansSand += sandPercent[4];
        if((1<=r-1 && r-1<=N) && (1<=c && c<=N)){
            A[r-1][c] += sandPercent[5];
        } else ansSand += sandPercent[5];
    }
    
    
    A[r][c] = 0;
   
}


int main(){
    
    cin >> N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    int r = N/2 + 1;
    int c = N/2 + 1;
    //for(int i = 1; i<=N/2 ; i++){ //N/2번 돈다
    bool chk = false;
    int repeat = 0;
    while(1){
        
        for(int i = 0; i<4; i++){
            if(chk) break;
            
            if(i%2==0){repeat++;}
            for(int j = 1; j<=repeat; j++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr==1 && nc==1) { chk = true; }
                
                if(A[nr][nc]!=0) {
                    int sum = 0;
                   sandPercent[0] = (int)A[nr][nc]*0.01;    //sum+=(sandPercent[0]*2);
                   sum+=sandPercent[0];sum+=sandPercent[0];
                   sandPercent[1] = (int)A[nr][nc]*0.02;    //um+=(sandPercent[1]*2);
                   sum+=sandPercent[1];sum+=sandPercent[1];
                   sandPercent[2] = (int)A[nr][nc]*0.05;    //sum+=sandPercent[2];
                   sum+=sandPercent[2];
                   sandPercent[3] = (int)A[nr][nc]*0.07;    //sum+=(sandPercent[3]*2);
                   sum+=sandPercent[3];sum+=sandPercent[3];
                   sandPercent[4] = (int)A[nr][nc]*0.1;     //sum+=(sandPercent[4]*2);
                   sum+=sandPercent[4];sum+=sandPercent[4];
                   int alpha = A[nr][nc] - sum;
                   sandPercent[5] = alpha;
                   
                   
                   moveSand(nr, nc, i);
                }
                
               
                r = nr;
                c = nc;
               
                if(chk) break;
                
            }if(chk) break;
            
        }if(chk) break;
    }

    
    cout << ansSand;
    return 0;
}
