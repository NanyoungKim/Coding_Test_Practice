#include <iostream>
#include <cmath>

using namespace std;


int main(){
    
    
    int N, ans = 0;
    cin>>N;
    int x = 0;
    cout << pow(10,0) << endl;
    int r;
    if(N>=10){

        for(int x = 0; ; x++){

            r = pow(10.0,x);
            if(N / r  >= x) {x++;}
            else break;
        }


        for(int i = 1; i<=x; i++){

            int p = pow(10.0, i-1);
            ans += 9*p * i;

        }

               
        ans += (N-r + 1) * (x+1);
    }

    else{
        ans = N;
    }

    cout << ans << "\n";

    
    return 0;
}
