//
//  NGV1.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/16.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//
#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
        long long  K,P,N;
        cin >> K >> P >> N;

        
        for(int i = 0; i<N; i++){
                K  = (K*P) % 1000000007;
        }
        cout << K;
 return 0;
}
