#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int P[1001] = {0};
int dp[1001] = {0};
vector<int> vec;
int maxSum = 0;



int main(){
    
    
   
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> P[i];
    }

    dp[0] = 0;
    dp[1] = P[1];
    
    for(int i = 2; i<=N; i++){
        for(int j = 1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + P[j]);
        }
    }
    
    cout<<dp[N];
    
    
    
    
    
    return 0;
}
