#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T[15] = {0};
int P[15] = {0};

int ans = 0;

void dfs(int start, int sum){
    
    if(start>N) return;
    
    ans = max(ans, sum);
    
    for(int i = start; i<N; i++){
        dfs(i+T[i], sum+P[i]);
    }
        
        
//        if(visited[i]==0){
//
//            if(i+T[i]-1>N) continue;
//
//            for(int j = i; j<i+T[i]; j++){
//                visited[j] = 1;
//            }
//            sum+=P[i];
//            dfs(i);
//            sum-=P[i];
//            for(int j = i; j<i+T[i]; j++){
//                visited[j] = 0;
//            }
//        }
        
}


int main(){
    
    cin >> N;
    for(int i = 0; i<N; i++){
        cin>> T[i] >> P[i];
    }
    
    dfs(0,0);
    cout << ans << "\n";
    return 0;
}
