#include <iostream>
using namespace std;


//N = 1~200
int dp[201][201];

int main(){
    
    for(int i = 1; i<=200; i++){
        for(int j = 1; j<=200; j++){
            dp[i][j] = 0;
            if(j==1) { dp[i][j] = 1; continue;}
        }
    }
    
   
    

    int N, K;
    cin >> N >> K;


    for(int i = 2; i<=N; i++){
        for(int j = 2; j<=i; j++){

            for(int k = i-1; k>=j-1; k--){
                dp[i][j] += dp[k][j-1] % 1000000000;
            }
            if(j==2) {dp[i][j] += 2; dp[i][j] %= 1000000000;}
        }
    }

    cout << dp[N][K] << endl;
    
   
//    for(int i = 1; i<=N; i++){
//              for(int j = 1; j<=N; j++){
//                  cout << dp[i][j] << " ";
//           }
//           cout << endl;
//       }

    
    
    
    return 0;
}

