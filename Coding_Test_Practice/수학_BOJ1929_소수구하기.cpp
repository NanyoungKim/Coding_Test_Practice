#include <iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>


using namespace std;

int arr[1000001] = {0};
int main(){
    
    
    int M, N;
    cin >> M >> N;

   
    arr[1] = 1; //1은 소수 아님
    int k;
    for(int i = 2; i<=N; i++){
        
        
        if(arr[i] == 0){    //아직 체크 안됐으면
            
            if( i*i <= 1000001  ){
                for(k = i*i; k<=1000000; ){
                    arr[k] = 1;         //소수 아님
                    k+=i;
                }
            }
            else break;
        }
        
    }
    
    
    
    
    
    
    
    for(int i = M; i<=N; i++){
        if(arr[i] == 0 ) cout << i << "\n";
    }
        
  
    
    
    return 0;
}
