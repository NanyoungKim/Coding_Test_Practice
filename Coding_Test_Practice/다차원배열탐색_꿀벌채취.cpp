//
//  다차원배열탐색_꿀벌채취.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/03.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int T, N,M,C;
int arr[10][10];
int honey[10][10];
//int visited[10][10];
//stack<int> stk;
//stack<int> stk2;
//
//int sum = 0;
//int maxx = 0;
vector<int> vec;


bool chk(int row, int col){
    
    
    if(col+M <= N){
        return true;
    }
    else{
        return false;
    }
}

bool visited[5] = {true,};
vector<int> pick;
int s = 0;
int m = 0;
int ans = 0;
void search(int r, int c){
    
    
    
    
    if(s > C){
        return;
    }
    
    
    for(int i = 0; i<M; i++){
        
        if(visited[i]){
            s += arr[r][c];
            visited[i] = false;
            pick.push_back(arr[r][c]);
            search(r,c);
            
            pick.pop_back();
            visited[i] = true;
            
            
            
            
            
            
        }
        
    }
    for(int k = 0; k<pick.size(); k++){
        m += pick[k]*pick[k];
    }
    
    if(m>ans){
        ans = m;
    }
    
    
    
    
}

int func(int i, int j){
    
    int sum = 0;
    int sqsum = 0;
    
    
            
    if(chk(i,j)){   //범위 안의
        
        
        for(int p = 0; p<M; p++){
             sum += arr[i][j+p];
             honey[i][j+p] = 1;
             sqsum += arr[i][j+p]*arr[i][j+p];
        }
        
        
        if(sum<C){
//            max = sqsum;
//            vec.push_back(max);
            
            return sqsum;
            
        }
        else{
                    
                    
                    
            search(i,j);
                    
            return ans;
                    
                    
                    
        }
                
                
                
                
                
                
                
            
    }
    else{       //범위 넘어가면
        return 0;
    }
    
    
    
}







//void search(int ro, int co, int sum, int cnt){
//
//
//
//    stk.push(arr[ro][co]);
//    sum += stk.top();
//
//
//    //백트래킹. 종료뷰
//    if(sum > C){
//        stk.pop();
//        return;
//    }
//
//
//    search(ro, co+1, sum, cnt+1);
//
//
//    while(stk.size() != 0){
//        maxx += stk.top() * stk.top();
//        stk2.push(stk.top());
//        stk.pop();
//
//
//    }
//
//
//    //원상복귀
//    while(stk2.size() != 0){
//        stk.push(stk2.top());
//        stk2.pop();
//    }
//
//    return;
//
//
//
//
//
//
//
//
//
//
//    //재귀
//
//
//
//
//
//
//    //원상복귀
//
//
//
//
//}
//
//






int main(){
    
    
    cin >> T;
   
    
    
    while(T--){
        
        cin >> N >> M >> C;
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                
                cin >> arr[i][j];
                honey[i][j] = 0;
     
            }
            
        }
        
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
               
                func(i,j);
            }
            
        }
        
        
        
        
        
        
        
        cout << "#" << T << " " ;
        
    }
    
    
    return 0;
}
