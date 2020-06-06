//
//  완전탐색_사다리조작(test).cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/04.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>

int N = 0;  //세로선
int M = 0;  //가로선
int H = 0;  //가로선을 넣을 수 있는 위치의 개수
int **arr;


using namespace std;


//잘 들어가는지 확인하는 함수
bool chkLadder(int r, int c){
    
    int cnt = 0;

    for(int j = 1; j<N+1; j++ ){                //열
        int startcol = j;
        for(int i = 1; i<M+1; i++){             //행
            
            if(arr[i][j] == 1){ //->
                i++;
                j++;
            }
            else if((arr[i][j] == 0) && (arr[i][j-1] ==1)){
                i++;
                j--;
            }
            else{
                i++;
            }
            
            
            
        }
        
        if(startcol == j){
            cnt++;
        }
        
    }
    
    if(cnt == N){
        return true;
    }
    else{
        return false;
    }
    
    
    
    
}


bool chk(int r, int c){
    
    if( (arr[r][c] != 1) && (arr[r][c-1] == 0)){
        return true;
    }
    else{
        return false;
    }
    
}

//막대를 추가하는 함수
void addLadder(int r, int c){
    
   
    
    
    if(chkLadder(r,c)){
        return;
    }
    
    
    else{
        
        if(chk(r,c)){
            arr[r][c] = 1;
            addLadder(r,c+1);
        }
        else{
            
        }
        
        
        
    }
    
    
    
    
}











int main(){
    
    int a,b;
    cin >> N >> M >> H;
    
    
   arr = new int*[M+1];
    for(int i = 0; i<M+1; i++){
        arr[i] = new int[N+1];
        memset(arr[i], 0, sizeof(int)*(N+1));
    }
    
    
    for(int i = 0; i<M; i++){
        
        cin >> a >> b;
        arr[a][b] = 1;

    }
    
    
    
    
    
    
    
    
    return 0;
}
