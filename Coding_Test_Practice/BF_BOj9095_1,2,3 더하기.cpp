#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[3] = {1,2,3};
int cnt = 0;
vector<int> choiceVec;


void sumFunc(int sum){
    
    if(n<sum) return;
    
    if(n==sum){
        cnt++;
        return;
    }
    
    
    for(int i = 0; i<3; i++){
        
        sum+=num[i];
        choiceVec.push_back(num[i]);
        
        sumFunc(sum);
        choiceVec.pop_back();
        sum-=num[i];
        
    }
    
    
    
    
}



int main(){
    
    
    
    int T;
    cin >> T;
    for(int tc = 0; tc<T; tc++){
    
        cin >>n;
        sumFunc(0);
        cout << cnt << "\n";
        
        
        
        cnt = 0;
        choiceVec.clear();
        
    }
    
    
    
    
    
    return 0;
}
