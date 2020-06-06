//
//  완전탐색_숫자카드(test).cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/04.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

vector<int> answer;
vector<int> vec;
int arr[3] = {2,5,7};
bool chkArr[3] = {true,true,true};
void search(int s, int c){
    
    
    if(c == 3){         //세개 다 골랐으면
        int ans = 100*vec[0] + 10*vec[1] + vec[2];
        answer.push_back(ans);
        return;
    }
    
    for(int i = 0; i<s; i++){
        
        
        if(chkArr[i]){          //아직 카드 안 쓴거면
            vec.push_back(arr[i]);
            chkArr[i] = false;          //이미 쓴 것이라고 표시
            search(s,c+1);
            
            vec.pop_back();
            chkArr[i] = true;
        }
        else{
            continue;
        }
        
        
    }
    
    
    
    
}






int main(){
    
    int size = 3;
    int cnt = 0;
    search(size, cnt);
    
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    
    return 0;
}
