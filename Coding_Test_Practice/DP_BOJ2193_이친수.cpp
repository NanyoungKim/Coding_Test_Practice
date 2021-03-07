#include <iostream>
using namespace std;

//자료형 int로 하면 통과 안 됨!
long long dp[91][2];
int main(){
    int T; cin >> T;
    
    for(int i = 0; i<=90; i++){
        for(int j = 0; j<=1; j++){
            dp[i][j] = 0;
        }
    }
    
    dp[1][0] = 0; dp[1][1] = 1;
    
    for(int i = 2; i<=90; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    for(int i = 0; i<T; i++){
        int N; cin >> N;

        cout << dp[N][0] + dp[N][1];

    }
    
    return 0;
}

