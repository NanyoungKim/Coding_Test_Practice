#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int k;
vector<int> vec;
vector<int> ans;
int visited[50] = {0};


void dfs(int toPick, int idx ){
    
    if(toPick==0){
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }cout << "\n";
        return;
    }
    
    
    for(int i = 0; i<vec.size(); i++){
        
        if(visited[i] == 0 && idx < i){
            visited[i] = 1;
            ans.push_back(vec[i]);
            dfs(toPick-1, i);
            ans.pop_back();
            visited[i] = 0;
        }
    }
}
int main(){


    
    int num;
    
    while(1){
        
        memset(visited,0,sizeof(visited));
        vec.clear();
        ans.clear();
        
        cin >> k;
        if(k==0) break;
        
        for(int i = 0; i<k; i++){
            cin >> num;
            vec.push_back(num);
        }
        
        
        dfs(6, -1);
        cout << "\n";
        
        
    }
    
    
    

    return 0;
}

