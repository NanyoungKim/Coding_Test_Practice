//
//  BS_BOj1789_수들의 합.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/26.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


int main(){
    
    long S; cin >> S;
    
    long ans = 0;
    long start = 1; long end = S;
    
    while(start<=end){
        long mid = (start+end)/2;
        
        if(mid*(mid+1)/2 <= S){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    
    cout << ans;
    
    return 0;
}
