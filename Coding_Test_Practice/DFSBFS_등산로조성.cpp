//
//  DFSBFS_등산로조성.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/06.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;
int T, N, K;
int **arr;
int visit[8][8];

vector<int> maxStart;
vector<int> lengthLoad;

map<int,int> maxMap;
stack<int> stk;
        
        //상,하, 좌, 우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


//시작할 최대 요소를 찾는 함수
void maxSearch(){
    
    int m = 0;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(arr[i][j] >= m){                 //배열에서 가장 큰 수를 찾음
                m = arr[i][j];
            }
        }
    }
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(m == arr[i][j]){
                
                maxMap.insert(make_pair(i, j));         //찾은 큰 수랑 똑같은 요소의 인덱스 저장
               
                
            }
        }
    }
    
    
    
    
    
}

bool chk(int r, int c){     ///범위 안에 있는지 체크하는 함수
    
    if((0<=r) && (r<=N-1) && (0<=c) && (c<=N-1)){
        return true;
    }
    else {
        return false;
    }
}



//등산로를 찾는 함수
int remainK = K;
void mountain(int r, int c){
    
    
    visit[r][c] = 0;
    stk.push(arr[r][c]);
    
    
    for(int i = 0; i<4; i++){   //상하좌우
        
        int nRow = r + dx[i];
        int nCol = c + dy[i];
        
        if(chk(nRow, nCol)){    //  범위 안에 있으면
            
            if((visit[nRow][nCol]) &&  (arr[r][c] > arr[nRow][nCol])){      //높이가 더 낮고 아직 방문 안 했으면
                
                visit[nRow][nCol] = 0;
                stk.push(arr[nRow][nCol]);        //해당 지점을 push
                mountain(nRow,nCol);
                
                lengthLoad.push_back(stk.size());
                stk.pop();
                visit[nRow][nCol] = 1;
                
            }
            else if(visit[nRow][nCol] && (arr[r][c] >  arr[nRow][nCol]-K )       ){
                
                
                for(int p = 0; p<remainK; p++){
                    
                    if((arr[nRow][nCol] - p) < arr[r][c]){      //깎았는데 갈 수 있다면
                        
                        visit[nRow][nCol] = 0;
                        stk.push(arr[nRow][nCol]);
                        remainK--;
                        mountain(nRow,nCol);
                        
                        lengthLoad.push_back(stk.size());
                        stk.pop();
                        visit[nRow][nCol] = 1;
                        
                        
                        
                        
                    }
                }
                
                
            }
        }
        else{
            continue;
        }
        
    }
    
  
    
    
    
    visit[r][c] = 1;
    
    
    
    
}




int main(){
    
    
    cin>>T;
    cin >> N >> K;
    
    
    
    arr = new int*[N];
    for(int i = 0; i<N; i++){
        arr[i] = new int[N];
    }
    
                
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> arr[i][j];
            visit[i][j] = 1;            //방문할 수 있는 삳태 = 1
        }
    }
    
    
    map<int,int> ::iterator iter;
    
    
    for(iter = maxMap.begin(); iter!=maxMap.end(); iter++){
        
        mountain(iter->first, iter->second);
        
    }
    
    
    
    
    
    
    return 0;
}
