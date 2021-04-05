//
//  BF_BOJ16938_캠프준비.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/04.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,L,R,X;

vector<int> vec;
vector<int> pickVec;
int answer = 0;
int visited[15] = {0};


void pickDFS(int toPick, int start,  int sum, int maxi, int mini){
        
    if(toPick==0){
        if((L<=sum && sum<=R) && (X<= maxi - mini)) {
            cout << sum << " " << maxi << " " << mini << endl;
            answer++;
        }
        return;
    }
    
    for(int i = start; i<vec.size(); i++){
        if(visited[i]==0){
            visited[i] = 1;
            pickDFS(toPick-1, i, sum+vec[i], maxi<vec[i] ? vec[i]:maxi, vec[i]<mini ? vec[i]:mini);
            visited[i] = 0;
        }
    }
    
    
}


int main(){
    
    cin >> N >> L >> R >> X;
    
    for(int i = 0; i<N; i++){
        int num;    cin>> num;
        vec.push_back(num);
    }
    
    for(int i = 2; i<=N; i++){
        cout << i << endl;
        pickDFS(i,0, 0, 0, 1000001);
    }
    cout << answer;

    return 0;
}
