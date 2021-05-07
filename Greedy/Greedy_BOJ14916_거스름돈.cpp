//
//  Greedy_BOJ14916_거스름돈.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/07.   10:27~10:47
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int ans = 0;
    
    int n;
    cin>>n;
    
    if(n<5){
        if(n%2==0) ans = n/2;
        else ans = -1;              //거스름돈 5원보다 작은데 2원으로도 낼 수 없는 경우
    }
    else{

        if(n%5==0){
            ans = n/5;
        }
        else{
            
            int q = n/5;
            int remain = n - q*5;
            
            if(remain%2==0){
                ans = q + remain/2;
            }
            else{
                ans = (q-1) + (remain+5)/2;
            }
        }
    }
    

    cout << ans;
    
    return 0;
}
