#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Arr[100001] = {0};
int DP[100001] = {0};

int main(){
    
    
    int N;
    cin >> N;
    int ans;
    int maxi = 0;
        
    for(int i = 0; i<=N; i++){ cin >> Arr[i];}
    
    DP[0] = Arr[0];
    ans = Arr[0];
    for(int i = 1; i<N; i++){
        
        DP[i] = max(DP[i-1] + Arr[i], Arr[i]);
        ans = max(ans, DP[i]);
        
        //cout << DP[i] << " ";
    }
    
    cout << ans;
    

    
    return 0;
}
