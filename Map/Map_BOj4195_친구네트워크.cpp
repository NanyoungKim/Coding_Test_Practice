//
//  Map_BOj4195_친구네트워크.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/06/30.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int test_case = 0;
    cin >> test_case;
    for(int t=1; t<=test_case; t++){
        
        unordered_map<string,int> umap;
        
        int F; cin >> F;
        for(int i = 0; i<F; i++){
            string name1, name2;
            cin >> name1 >> name2;
            
            unordered_map<string, int> :: iterator it;
            
            if(umap.find(name1)==umap.end() && umap.find(name2)==umap.end()){   //둘다 없으면
                umap[name1] = 2;
                umap[name2] = 2;
                cout << umap[name2] << "\n";
            }
            else if(umap.find(name1) != umap.end() && umap.find(name2) == umap.end()){  //1만 있음
                int cnt = umap[name1];
                for(it = umap.begin(); it!=umap.end(); it++){
                    it->second = cnt + 1;
                }
                umap[name2] = cnt+1;
                
                cout << umap[name2] << "\n";
            }
            else if(umap.find(name1) == umap.end() && umap.find(name2) != umap.end()){  //2만 있음
                int cnt = umap[name2];
                for(it = umap.begin(); it!=umap.end(); it++){
                    it->second = cnt + 1;
                }
                umap[name1] = cnt + 1;
                
                cout << umap[name1] << "\n";
            }
            else{   //둘다 있음
                int cnt1 = umap[name1];
                int cnt2 = umap[name2];
                for(it=umap.begin(); it!= umap.end(); it++){
                    it->second = cnt1 + cnt2;
                }
                cout << umap[name1] << "\n";
            }
        }
        
    }
    
    return 0;
}
