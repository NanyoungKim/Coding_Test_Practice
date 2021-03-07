
#include <iostream>
#include <algorithm>

using namespace std;


int rgbArr[1001][3];
int dp[1001][3];

int main(){
    
    int N; cin>>N;
    

    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=2; j++){
            scanf("%d", &rgbArr[i][j]);
        }
    }
    rgbArr[0][0] = 0;   rgbArr[0][1] = 0;   rgbArr[0][2] = 0;
    dp[0][0] = 0;   dp[0][1] = 0;   dp[0][2] = 0;
    dp[1][0] = rgbArr[1][0];    dp[1][1] = rgbArr[1][1];    dp[1][2] = rgbArr[1][2];

    
    for(int i = 2; i<=N; i++){
        
        dp[i][0] = min(rgbArr[i][0] + dp[i-1][1], rgbArr[i][0] + dp[i-1][2]);
        dp[i][1] = min(rgbArr[i][1] + dp[i-1][0], rgbArr[i][1] + dp[i-1][2]);
        dp[i][2] = min(rgbArr[i][2] + dp[i-1][0], rgbArr[i][2] + dp[i-1][1]);
        
        int mini=1000000; //1000*1000
        for(int j = 0; j<=2; j++){
            mini = min(mini, dp[i][j]);
        }
        
    }
    
    int ans=1000000;
    for(int i = 0; i<3; i++){
        ans = min(ans, dp[N][i]);
    }
    
//    for(int i = 0; i<=N; i++){
//        for(int j=0; j<3; j++){
//            cout << dp[i][j] << " " ;
//        }
//        cout << "\n";
//    }
    
    
    cout << ans;
    return 0;
}
