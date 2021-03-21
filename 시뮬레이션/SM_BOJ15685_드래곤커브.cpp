//
//  SM_BOJ15685_드래곤커브.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/21.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define MAX 100
int map[MAX+1][MAX+1];

//오 위 왼 아
int dr[4] = {0,-1,0,1};
int dc[4] = {1, 0, -1, 0};




bool chkFour(int r, int c){
    if(map[r][c] && map[r][c+1] && map[r+1][c] && map[r+1][c+1]) return true;
    else return false;
}

stack<int> copyFunc(stack<int> stk){
    
    stack<int> tmp, res;
    while(!stk.empty()){
        tmp.push(stk.top());
        stk.pop();
    }
    
    while(!tmp.empty()){
        res.push(tmp.top());
        tmp.pop();
    }
    return res;

}


int main(){
    
    for(int i = 0; i<=MAX; i++){
        for(int j = 0; j<=MAX; j++){
            map[i][j] = 0;
        }
    }
    
    
    int N; cin >> N;
    
    int x, y, d ,g, row, col, nextR, nextC, nextD;
    for(int i = 0; i<N; i++){
        
        stack<int> stkD;
        
        cin >> x >> y >> d >> g;
        map[y][x] = 1;
        //0세대
        nextR = y + dr[d];
        nextC = x + dc[d];
        map[nextR][nextC]  = 1;
        stkD.push(d);
        
        row = nextR;
        col = nextC;
        
        //1세대 ~ g세대
        for(int i = 1; i<=g; i++){
            
            stack<int> copyStkD = copyFunc(stkD);
            
            while(!stkD.empty()){
                
                nextD = (stkD.top()+1) % 4;
                copyStkD.push(nextD);
                stkD.pop();
                
                nextR = row + dr[nextD];
                nextC = col + dc[nextD];
                map[nextR][nextC] = 1;
                //cout << nextR <<  "  /  " << nextC << "\n\n";
                
                row = nextR;
                col = nextC;
                
            }
            stkD = copyFunc(copyStkD);
        }
        
        
        
    }
    
    int ans = 0;
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            if(chkFour(i,j)) ans++;
        }
    }
    
    cout << ans;
    
    
    
    
    
    return 0;
}
