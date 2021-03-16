//
//  NGV_조립라인.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/16.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include<iostream>
#include <vector>


using namespace std;

int aTime[1001] = {0};
int bTime[1001] = {0};
int atob[1001] = {0};
int btoa[1001] = {0};
int main(int argc, char** argv)
{
    
    int N; cin >> N;
    
    for(int i = 1; i<=N-1; i++){
        cin >> aTime[i] >> bTime[i] >> atob[i] >> btoa[i];
    }
    cin >> aTime[N] >> bTime[N];
    
    
    int chk = 0, ans = 0;
    if(aTime[1] <= bTime[1]) {
        chk = 1;
        ans = aTime[1];
    }
    else {
        chk = 2;
        ans = bTime[1];
    }
    
    
    
    
    for(int i = 2; i<=N; i++){
        
        if(chk==1){ //현재 작업장 A
            if(aTime[i] <= bTime[i] + atob[i-1]){   //그대로 A->A
                ans += aTime[i];
            }
            else{   //A -> B
                ans += (bTime[i] + atob[i-1]);
                chk = 2;
            }
        }
        else{//현재 작업장 B
            if(bTime[i] <= aTime[i] + btoa[i-1]){   //b->b
                ans += bTime[i];
            }
            else{   ///b -> a
                ans += (aTime[i] + btoa[i-1]);
                chk = 1;
            }
  
        }
    }
    
    cout << ans;
    
    
    
    

 return 0;
}
