//
//  BF_BOJ16922_로마숫자만들기.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/03.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define I 1
#define V 5
#define X 10
#define L 50

int N;
int answer = 0;
int sum = 0;
bool visited[1001] = {0};
char cArr[4] = {'I','V','X','L'};
int iArr[4] = {1,5,10,50};

vector<int> sumVec;
vector<string> strVec;
string str = "";
void pickDFS(int toPick, int start, int s){
    
    
    if(toPick==0){
        if(visited[s]==false){
            answer++;
            visited[s]=true;
        }
        return;
    }
    
    for(int i = start; i<4; i++){
        pickDFS(toPick-1, i, s+iArr[i]);
    }
    
}


int main(){
    cin>>N;
    pickDFS(N, 0, 0);
    cout << answer;
    
    return 0;
}
