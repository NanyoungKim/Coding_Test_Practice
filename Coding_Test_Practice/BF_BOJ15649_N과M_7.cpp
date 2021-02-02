#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;

void dfs(int toPick){
    
    if(toPick==0){
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout <<"\n";
        return;
    }
    
    for(int i = 0; i<vec.size(); i++){
                    
            ans.push_back(vec[i]);
            dfs(toPick-1);
            ans.pop_back();
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
    
    dfs(M);
    
    
    
    
    return 0;
}
