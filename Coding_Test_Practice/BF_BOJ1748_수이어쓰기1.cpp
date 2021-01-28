#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    
    int N;
    cin >> N;
    int x = 1;
    int ans = 0;
    while(1){
    
        int q = N/pow(10,x);
        if(q>0){
            ans += (pow(10,x)-pow(10,x-1)) * x;
        }
        else{
            ans += (N-pow(10,x-1) + 1) * x;
            break;
        }
        x++;
    }
    
    cout  << ans << "\n";

    return 0;
}
