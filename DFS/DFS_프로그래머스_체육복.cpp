//
//  DFS_프로그래머스_체육복.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/30.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;
vector<int> vec;
int arr[31];
int d[2] = {1, -1};
int visited[31] = {0};
int mini = 100;
void DFS(int n){

    int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(arr[i]==0) cnt++;
        }
        if(cnt<mini) mini = cnt;
        
    for(int i = 0; i<vec.size(); i++){
        for(int j = 0; j<2; j++){
            int next = vec[i] + d[j];
            if(next<1 || next>n || arr[next]!=0) continue;      //범위 넘어가거나 옆사람 줄 필요 없으면
            
            if(visited[vec[i]]==0){
                visited[vec[i]] = 1;
                arr[vec[i]] -= 1;
                arr[next] += 1;
                DFS(n);
                arr[next] -= 1;
                arr[vec[i]] += 1;
                visited[vec[i]] = 0;
            }
            
        }
    }
}


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int cnt=0;
    for(int i = 0; i<=31; i++){
        arr[i] = 1;
    }
    for(int i = 0; i<lost.size(); i++){ arr[lost[i]] -= 1;}             //안 가져온 사람
    for(int i = 0; i<reserve.size(); i++){ arr[reserve[i]] += 1;}       //여분 가져온 사람
    
    for(int i = 1; i<=n; i++){
        if(arr[i]==2) vec.push_back(i); //여분 체육복 갖고 온 사람이 도둑 맞은 경우는 arr[i] = 1이므로 arr[i] = 2인 경우만 인덱스 push
    }
    
    DFS(n);
    answer = n-mini;

    
    return answer;
}
