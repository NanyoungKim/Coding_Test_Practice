#include <iostream>
#include <algorithm>

using namespace std;

int dp[100489] = {0};

int main(){
     for(int i = 1; i<=100000; i++){
         dp[i] = 10000;
     }
    
    int N;
    cin >> N;

    dp[0] = 0; dp[2] = 2; dp[3] = 3;
    for(int i = 1; i*i<=100000; i++){
        dp[i*i] = 1;
    }
    
    for(int i = 1; i<=316; i++){
        for(int j = i*i+1; j<=(i+1)*(i+1)-1; j++){
            for(int k = 1; k<=i; k++){
                dp[j] = min(dp[j], dp[j-k*k] + dp[k*k]);
            }
        }
    }
    

    cout << dp[N];

    
    
    return 0;
}
