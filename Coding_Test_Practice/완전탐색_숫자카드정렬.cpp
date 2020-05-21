//
//  완전탐색_숫자카드정렬.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/05/21.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <stack>

int cardArr[3] = {2,5,7};
bool checkArr[3] = {1,1,1};

int size = sizeof(cardArr)/sizeof(cardArr[0]);
int toPick = size;

vector<int> answer;
vector<int> vec;
stack<int> stk;

int num;

void search(int n, int toPick){
    
    
    if(toPick == 0){
        
        num = 100*vec[0] + 10*vec[1] + vec[2];
        answer.push_back(num);
        
        
    }
    
    else{
        
        for(int i = 0; i<n; i++){
            
            if(checkArr[i] == true){
                
                vec.push_back(cardArr[i]);
                checkArr[i] = false;
                search(n, toPick-1);
                
                vec.pop_back();
                checkArr[i] = true;
                
                
            }
            else{
                continue;
            }
            
            
        }
        
        
        
        
    }
    
    
    
    
    
    
}





int main(){
    
    
    
    search(size, toPick); //3
    
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    
    return 0;
}
