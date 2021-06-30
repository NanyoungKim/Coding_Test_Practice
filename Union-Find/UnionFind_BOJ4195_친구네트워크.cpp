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

int sizeArr[200000];
int parent[200000];

int getParent(int x){
    if(x==parent[x]) return x;
    else return parent[x] = getParent(parent[x]);
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int test_case = 0;
    cin >> test_case;
    for(int t=1; t<=test_case; t++){
        
        unordered_map<string,int> umap;
        
        //F : 0~99,999 -> 친구 수 : 0 ~ 199,998 -> idx = 1~199,999 -> arr크기 = 200,000

        for(int i = 0; i<200000; i++){
            parent[i] = i;
            sizeArr[i] = 1;
        }
        
        int nodeNum = 0;
        
        int F; cin >> F;
        for(int i = 1; i<=F; i++){
            
            string name1, name2;
            cin >> name1 >> name2;
            
            if(umap.find(name1) == umap.end()){
                umap[name1]  = nodeNum++;
                
            }
            if(umap.find(name2) == umap.end()){
                umap[name2] = nodeNum++;
            }
            
            //find
            int n1 = umap[name1];
            int n2 = umap[name2];
            int p1 = getParent(n1);
            int p2 = getParent(n2);
            
            //union
            if(p1!=p2) {
                if(sizeArr[p1] < sizeArr[p2]) swap(p1, p2);
                sizeArr[p1] += sizeArr[p2];
                parent[p2] = p1;
            }
        
            cout << sizeArr[p1] << "\n";
            
        }
        
    }
    
    
    
    
    return 0;
}
