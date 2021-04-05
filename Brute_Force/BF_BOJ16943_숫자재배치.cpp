//
//  BF_BOJ16943_숫자재배치.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/05.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int visited[10] = {0};
vector<char> vec;
int A,B;
string strB;
int maxi = 0;
int answer = 0;
void DFS(int toPick, string str){
    
    if(toPick==0){
        int num = stoi(str);

        if(num!=A && num<B){        //B보다 작으면서
            if(maxi<num) {          //그 중 가장 큰 값
                maxi = num;
                answer = num;
            }
        }
    }
    
    for(int i = 0; i<vec.size(); i++){
        
        if(visited[i]==0){
            if(str.length()==0 && vec[i]=='0') continue;        //처음 0이 오면 안됨
            visited[i] = 1;
            str.push_back(vec[i]);
            DFS(toPick-1, str);
            str.pop_back();
            visited[i] = 0;
        }
    }
    
    
}


int main(){
    
    
    cin >> A >> B;
    
    string strA = to_string(A);
    string strB = to_string(B);
    int nLen = (int)strA.length();
    
    for(int i = 0; i<nLen; i++){
        vec.push_back(strA[i]);
    }
    
    DFS(nLen, "");
    if(answer==0) answer=-1;
    cout << answer ;
    
    return 0;
}
