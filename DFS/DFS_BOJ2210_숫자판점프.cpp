//
//  DFS_BOJ2210_숫자판점프.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/11.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char map[5][5];
//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

vector<string> strVec;
void DFS(int r, int c, int toPick, string str){
        
    if(toPick==0){
        if(find(strVec.begin(), strVec.end(), str) == strVec.end()){
            strVec.push_back(str);
        }
        return;
    }
    
    for(int i = 0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr<0 || nr>=5 || nc<0 || nc>=5) continue;
        
        str.push_back(map[nr][nc]);
        DFS(nr, nc, toPick-1,str);
        str.pop_back();
    }
}

int main(){
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i<5; i++){
           for(int j = 0; j<5; j++){
               DFS(i,j,6, "");
           }
    }

    cout << strVec.size();
    
    return 0;
}
