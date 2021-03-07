#include <iostream>
#include <algorithm>

using namespace std;

int triArr[500][500];
int dp[500][500];


int main(){
    
    int n; cin>>n;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            scanf("%d", &triArr[i][j]);
        }
    }
    
    dp[0][0] = triArr[0][0];
    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0] + triArr[i][0];
        dp[i][i] = dp[i-1][i-1] + triArr[i][i];
    }
    
    for(int i = 2; i<n; i++){
        for(int j = 1; j<=i-1; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triArr[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans;
    
    
    return 0;
}

