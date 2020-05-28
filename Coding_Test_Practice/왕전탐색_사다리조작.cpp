//
//  왕전탐색_사다리조작.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/05/23.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;

int N,M,H;                //세로선, 가로선, 세로선마다 가로선을 놓을 수 있는 위치의 개수
int **arr;


int add1(int r, int c, int res){
    
    if(res == 1){
        arr[r][c] = 1;
        arr[r][c+1] = 2;
    }
    else if(res == 2){
        arr[r][c] = 2;
        arr[r][c-1] = 1;
    }
    else{
        //윗칸에서 탐색 chkArr(r, c-1);
    }
    
}




bool chkArr(int r, int c){
    
    int res = 0;
    if((arr[r][c-1] != 0) && (arr[r][c+1] != 0)) {//양쪽에 길 있음
        res - 0;
        
    }
    else if((arr[r][c-1] == 0) && (arr[r][c+1] == 0)){  //둘다 없음
        res = true;
    }
    else{
        if((arr[r][c-1]) == 2){
            res = true;             //arr[r][c] == 1가능, 그러면 arr[r][c+1]도 2됨
        }
    }
    
    
}



void search(int r, int c){
    for(int i = r-1; i<N; i++){               //열 (세로)
        int chk = i;
        for(int j = c-1; j<M; j++){           //행 (가로)
            
            if(arr[j][i] == 1){
                i++;
                j++;
            }
            else if(arr[i][j] == 2){
                 i--;
                 j--;
             }
             else{
                 j++;
             }
                                
        }
            
        if(chk != i){
            arr[j-1][i] =
            search(
        }
        
            
    }
}








int main(){
    
   
    cin >> N >> M >> H;
    
  
    arr = new int*[M];
    for(int i = 0; i<N; i++){
        arr[i] = new int[M];
        memset(arr[i], 0, sizeof(int)*M);
        
    }
   
    
    for(int i = 0; i<M; i++){
        
        int a, b;
        
        cin >> a >> b;
        
        arr[b-1][a-1] = 1;      // -> 방향으로 이동 가능
        arr[b][a-1] = 2;    // <- 방향으로 이동 가능
        
        
    }
    
    
    serach(1,1);
    
    
    
    
    
    
    
    
    return 0;
}
