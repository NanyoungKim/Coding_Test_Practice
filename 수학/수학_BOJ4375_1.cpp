//
//  수학_BOJ4375_1.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/28.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int N;
    int k = 0;
    while(cin >> N){
        int ans = 1;
        k = 1;
        
        while(1){
            if(ans % N == 0){
                break;
            }
            else{
                k++;
                ans = ans*10 + 1;
                ans %= N;
            }
        }
        
        cout << k << "\n";
    }

    return 0;
}
