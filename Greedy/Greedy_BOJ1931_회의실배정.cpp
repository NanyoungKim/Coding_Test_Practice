//
//  Greedy_BOJ1931_회의실배정.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/12.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


int main(){
    
    int N; cin >> N;
    vector<pair<int,int>> vec;
    int a, b;
    
    for(int i = 0; i<N; i++){
        cin >> a >>b;
        vec.push_back(make_pair(b,a));
    }
    
    sort(vec.begin(), vec.end());
    int ans = 1;
    int tmp = vec[0].first;
    for(int i = 1; i<N; i++){
        if(vec[i].second<tmp) continue;
        else{
            tmp = vec[i].first;
            ans+=1;
        }
    }
    cout << ans;
    return 0;
}
