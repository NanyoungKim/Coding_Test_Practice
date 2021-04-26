//
//  BS_BOJ2417_정수 제곱근.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/26.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    long long n;
    cin >> n;
    
    long long ans = 0;
    
    long long start = 0;
    long long end = sqrt(n);            
    long long mid;
    while(start<=end){
        mid = (start+end)/2;
        if(mid >= sqrt(n)){
            end = mid-1;
        }
        else start = mid+1;
    }
    
    //cout << mid;
    
    
    if(mid*mid == n) cout << mid;
    else cout << mid + 1;

    
    
    
    
    
    return 0;
}
