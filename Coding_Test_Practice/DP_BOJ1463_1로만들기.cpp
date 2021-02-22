#include <iostream>
#include <algorithm>

using namespace std;

 int X;
int ans = 1000000;

int dp[1000001] = {0};

int searchMin(int a, int b, int c){
    
    int min1, min2;
    
    if(dp[a]<dp[b]) {
        min1 = dp[a];
        if(dp[a]<dp[c]) { min2 = dp[a]; }
        else min2 = dp[c];
        
    }
    else{
        min1 = dp[b];
        if(dp[b]<dp[c]) { min2 = dp[b];}
        else min2 = dp[c];
    }
    return min2;
}

int main(){
    
    int X; cin >> X;
    
    for(int i = 0; i<1000001; i++){dp[i] = 10000000;}
    
    int fir=0, sec=0, trd=0, mini=0; dp[0] = 0; dp[1] = 0;

    for(int i = 2; i<=X; i++){
        
        fir = i; sec= i; trd = i;
        
        if(i%3 == 0){
            fir = i/3;
        }
        if(i%2 == 0){
            sec = i/2;
        }
        
        trd = i-1;
        
       // cout << fir << " " << sec << " " << trd << "\n";
        mini = searchMin(fir, sec, trd);
        //cout << mini << "\n";
        dp[i] = mini + 1;
       // cout << i << " : " << dp[i] << endl;

        
    }
    cout << dp[X];
    
    return 0;
}
