//
//  Tree_BOJ19991_트리순회.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/07/01.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int N;
unordered_map<char, pair<char,char>> umap;

void preOrder(char c){
    if(umap.find(c) == umap.end()) return;
    else{
        cout << c;
        if(umap.find(umap[c].first) != umap.end() && umap[c].first != '.') preOrder(umap[c].first);
        if(umap.find(umap[c].second) != umap.end() && umap[c].second != '.') preOrder(umap[c].second);
    }
    
}
void inOrder(char c){
    if(umap.find(c) == umap.end()) return;
    else{
        if(umap.find(umap[c].first) != umap.end() && umap[c].first != '.') inOrder(umap[c].first);
        if(umap.find(umap[c].second) != umap.end() && umap[c].second != '.') inOrder(umap[c].second);
        cout << c;

    }
    
}
void postOrder(char c){
    if(umap.find(c) == umap.end()) return;
    else{
        if(umap.find(umap[c].first) != umap.end() && umap[c].first != '.') postOrder(umap[c].first);
        if(umap.find(umap[c].second) != umap.end() && umap[c].second != '.') postOrder(umap[c].second);
        cout << c;

    }
    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i = 0; i<N; i++){
        char p, n1, n2;
        cin >> p >> n1 >> n2;
        umap[p] = make_pair(n1, n2);
    }
    
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');

    
    return 0;
}
