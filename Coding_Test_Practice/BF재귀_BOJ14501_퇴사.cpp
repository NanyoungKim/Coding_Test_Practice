#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T[16] = {0};
int P[16] = {0};
int visited[16] = {0};

int sum = 0;
int ans = 0;
vector<int> sumVec;

void dfs(int chk){
    
    
    
    for(int i = 1; i<=N+1; i++){
        
        if(i>N){
            ans = max(ans, sum);
            return;
        }
        
        if(visited[i]==0){
            
            if(i+T[i]-1>N) continue;
            
            for(int j = i; j<i+T[i]; j++){
                visited[j] = 1;
            }
            sum+=P[i];
            dfs(i);
            sum-=P[i];
            for(int j = i; j<i+T[i]; j++){
                visited[j] = 0;
            }
            
            
            
        }
        
    }

    
    
}


int main(){
    
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin>> T[i] >> P[i];
    }
    
    dfs(0);
    
    
    cout << ans << "\n";
    
    
    
    return 0;
}
