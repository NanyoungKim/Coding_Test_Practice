//
//  Map_BOJ7785_회사에있는사람.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/06/30.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    map<string, string, greater<>> m;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        string name, EorL;
        
        cin >> name >> EorL;
        m[name] = EorL;
        
    }
    
    map<string, string>::iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        if(it->second == "enter"){
            cout << it->first << "\n";
        }
    }
        
    return 0;
}
