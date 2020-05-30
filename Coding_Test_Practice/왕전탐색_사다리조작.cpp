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

int answer = 0;




int chkAdd(int r, int c){
    
    int res = 0;                //연결 못하면 0, 오른쪽으로 연결하면 1, 왼쪽으로 연결하며 2
    
    if(c == 1){
        if((arr[r][c]==0) && (arr[r][c+1]==0)){
            res = 1;
        }
    }
    else if((2<=c) && (c <= N-1)){
        if((arr[r][c] == 0) && (arr[r][c-1] == 0) && (arr[r][c+1] == 0)){
            res = 1;
        }
        else if((arr[r][c] == 0) && (arr[r][c-2] == 0) && (arr[r][c-1] == 0) ){
            res = 2;
        }
    }
    else{
        if((arr[r][c-1] ==0) && (arr[r][c-2]==0)){
            res = 2;
        }
    }

       return res;
       
    
}


bool checkLadder(int _r, int _c){            //시작 col과 끝col이 같은지 검사하는 함수
    
    bool res;
   
    int ckeep = _c;
    int i;
    for(i = _r; i<=H; i++){
        
        if(arr[i][_c] == 1){
            _c++;
            //i++;
            
        }
        else if ((arr[i][_c] == 0) && (arr[i][_c-1])==1){
            _c--;
           // i++;
        }
       
     
    }
    
    if(ckeep == _c){
        res = true;
    }
    
    else{
        res = false;
        
    }
    return res;
}





void Ladder(int r, int c){
    
    //[r][c]는 시작점 =>  처음에는 1,1
    int chkadd = 0;
    bool chk = true;
    int startCol = 1;
    
    
    
    
    if(!checkLadder(r,c)) {     //처음 시작 열과 끝나는 열이 다르면 사다리 추가하고 다시 탐색
    
        for(int p = 1; p <= N; p++)   {         //열
            for(int q = 1; q <= H; q++){        //행
                
                
                chkadd = chkAdd(q,p);
                
                if(chkadd == 0){
                    continue;
                }
                
                else if(chkadd == 1){
                    arr[q][p] = 1;
                    
                    chk = checkLadder(1,startCol);          //사다리 추가 후 검사하기
                    if(chk){
                        answer++;
                        startCol++;
                    }
                    else{
                        arr[q][p] = 0;          //추가해도 자기 자리로 안 들어가면 추가했던 사다리 지우기
                    }
                }
                else{
                    arr[q][p-1] = 1;
                    
                    chk = checkLadder(1,startCol);
                    if(chk){
                        answer++;
                        startCol++;
                    }
                    else{
                        arr[q][p] = 0;
                    }
   
                }
                
            }
            
        }

    }
    
    




}





int main(){
    
   
    cin >> N >> M >> H;
    
  
    arr = new int*[H+1];
    for(int i = 0; i<H+1; i++){
        arr[i] = new int[N+1];
        memset(arr[i], 0, sizeof(int)*(N+1));
        
    }
   
    
    for(int i = 0; i<M; i++){
        
        int a, b;
        
        cin >> a >> b;
        
        arr[a][b] = 1;
        
        
    }
    
    
    
    for(int i = 1; i<=N; i++){
        Ladder(1,i);
        if(answer > 3){
            break;
        }
    }
    
    
    
    if(answer>3){
        cout << "-1" << endl;
    }
    else{
        cout << answer << endl;
    }
    
    
    
    
    
    
    return 0;
}
