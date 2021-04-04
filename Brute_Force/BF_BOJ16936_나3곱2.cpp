
//
//  BF_BOJ16936_나3곱2.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/03.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<long long> vecB;
vector<long long> vecA;
int visited[100] = {0};
int N;

pair<bool, int> isIn(long long num){
    for(int i = 0; i<N; i++){
        if(vecB[i]==num) return make_pair(true, i);
    }
    return make_pair(false, -1);
}

bool iscontinue = true;
void DFS(long long x, int cnt){



    if(cnt==N){
        iscontinue = false;
        for(int i = 0; i<N; i++){
            cout << vecA[i] << " ";
        }
        printf("\n");
        return;
    }

    //곱2
    pair<bool, int> p = isIn(2*x);
    if(p.first==true && visited[p.second]==0){
        visited[p.second] = 1;
        vecA.push_back(x*2);
        DFS(x*2, cnt+1);
        if(iscontinue){
            vecA.pop_back();
            visited[p.second] = 0;
        }else return;

    }


    //나3

    if(x%3 == 0){
        pair<bool, int> p2 = isIn(x/3);
        if(p2.first==false) return;
        else if(p2.first==true && visited[p2.second]==0){
            visited[p2.second] = 1;
            vecA.push_back(x/3);
            DFS(x/3, cnt+1);
            if(iscontinue){
                vecA.pop_back();
                visited[p2.second] = 0;
            }else return;

        }


    }

    if(iscontinue==false) return;
}


int main(){

    cin>>N;

    long long num;
    for(int i = 0; i<N; i++){
        scanf("%lld", &num);
        vecB.push_back(num);
    }

    for(int i = 0; i<vecB.size(); i++){
        visited[i] = 1;
        vecA.push_back(vecB[i]);
        DFS(vecB[i], 1);
        if(iscontinue==true){
            vecA.pop_back();
            visited[i] = 0;
        }else break;
    }

    return 0;
}

