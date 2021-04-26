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
    long x = sqrt(2*S);
    for(long i = x; i>=1; i--){
        if(i*i + i <=2*S){
            ans = i;
            break;
        }
    }
    cout << ans;
    
    return 0;
}
