//
//  완전탐색_테트로미노.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/05/30.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
using namespace std;


    //오, 아, 왼, 위
int dx[4] = {0,1,0,1};
int dy[4] = {1,0,-1,0};


int N,M = 0;
int arr[500][500];
bool chk[500][500];
int sum = 0;



int func(int r, int c, int cnt){
    
    sum = 0;
    int maxsum = 0;
    if(chk[r][c]){
        
        if((1<=c) && (c<M-1) && (0<=r) && (r<N-1)){          //ㅜ 모양
            sum = arr[r][c] + arr[r-1][c] + arr[r][c+1] + arr[r+1][c];
            if(sum > maxsum){
                maxsum = sum;
            }
        }
        
        if((0<=c) && (c<M-1) && (1<=r) && (r<N-1)){     //ㅏ 모양
            sum = arr[r][c] + arr[r-1][c] + arr[r+1][c] + arr[r][c+1];
            
            if(sum > maxsum){
                maxsum = sum;
            }
        }
        
        
        
        if((1<=c) && (c<M-1) && (1<=r) && (r<N)){       //ㅗ 모양
            sum = arr[r][c] + arr[r][c-1] + arr[r][c+1] + arr[r-1][c];
            
            
            if(sum > maxsum){
                maxsum = sum;
            }

        }
        
        if((1<=c) && (c<M) && (1<=r) && (r<N-1)){
            sum = arr[r][c] + arr[r][c-1] + arr[r-1][c] + arr[r+1][c];
            
            if(sum > maxsum){
                maxsum = sum;
            }
            
        }
        
    }
    
    return maxsum;
}

bool chkArr(int r, int c){
    
    bool res = false;
    if((r>=0) && (c>=0) && (r<=N-1) && (c<=M-1)){
        res = true;
    }
    return res;
    
}


int cnt = 1;

int tetromino(int cur_row, int cur_col, int cnt){
    
    
    if(cnt > 4){
        cnt = 0;
        return 0;
    }
    else{
        sum = 0;
        sum += arr[cur_row][cur_col];
        for(int i = 0; i<4; i++){                   //오,아,왼,위 반복
            
            int next_row = cur_row + dx[i];
            int next_col = cur_col + dy[i];
          
            
            if(chkArr(next_row, next_col)) {             //다음 depth를 방문할 수 있는 조건
               
                if(chk[next_row][next_col]){
                    sum += arr[next_row][next_col];
                    chk[next_row][next_col] = false;
                    tetromino(next_row, next_col, cnt+1);
                   
                    chk[next_row][next_col] = true;
                }
                
            }
            
           
            
        }
        
        
        
        
    }
    
    return sum;
    
    
    
}








int main(){
    
    
    int max = 0;
    int res = 0;
    
    
    cin >> N >> M;
    

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> arr[i][j];
            chk[i][j] = 1;
        }
        
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            
            chk[i][j] = 0;
            max = tetromino(i,j,0);
            chk[i][j] = 1;
            
            
            
         
            res = func(i,j,0);
            
            
            
            if(res>=max){
                max = res;
            }
            
            
            
            sum = 0;
     
        }
    }
    
    cout << max << endl;
    return 0;
}
