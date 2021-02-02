#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;

int visited[8]={0};

void dfs(int toPick, int num){
    
    if(toPick==0){
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout <<"\n";
    }
    
    for(int i = 0; i<vec.size(); i++){
        
        if(visited[i]==0 && num<vec[i]){
            
            visited[i]=1;
            ans.push_back(vec[i]);
            dfs(toPick-1, vec[i]);
            ans.pop_back();
            visited[i] = 0;
            
        }
    }
    
}

int main(){
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
        int a; cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    
    dfs(M, 0);
    
    
    
    
    return 0;
}
