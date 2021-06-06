//
//  수학_BOJ10989_수정렬하기3.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/06/06.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    int arr[10001] = {0,};
    int num =0;
    for(int i = 0; i<N; i++){
        cin >> num;
        arr[num] += 1;
    }
    for(int i = 1; i<=10000; i++){
        for(int j = 0; j<arr[i]; j++){
            cout << i << "\n";
        }
    }
    
    return 0;
}
