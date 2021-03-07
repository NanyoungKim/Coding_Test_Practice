#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> nextVec;
vector<int> prevVec;


int cal(vector<int> vec){
    int sum = 0;
    for(int i = 0; i<N-1; i++){
        sum += abs(vec[i] - vec[i+1]);
    }
    return sum;
}
int main(){


    cin >> N;
    int num;
    for(int i = 0; i<N; i++){
        cin >> num;
        nextVec.push_back(num);
        prevVec.push_back(num);
    }
    
    int maxi = 0;
    int ret;
    do{
        ret = cal(nextVec);
        if(maxi < ret) {
            maxi = ret;
        }
        
        
    } while(next_permutation(nextVec.begin(), nextVec.end()));

    while(prev_permutation(prevVec.begin(), prevVec.end())){
    
        ret = cal(prevVec);
        if(maxi < ret) {
            maxi = ret;
        }
        
    }

    
    cout << maxi;
    return 0;
}


