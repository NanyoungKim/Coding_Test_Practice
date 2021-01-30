#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> heightVec;
bool isVisited[9] = {0};
bool chk = false;
vector<int> ansVec;
int ans = 0;

void Func(int sum, int toPick){
    
    if(toPick==0){
        
        if(sum==100){
            chk = true;
            return;
        }
  
    }
    
    for(int i = 0; i<9; i++){
        
        if(isVisited[i]==0){
            isVisited[i] = 1;
            ansVec.push_back(heightVec[i]);
            sum+=heightVec[i];
        
            Func(sum, toPick-1);
            if(chk){ break;}
            
            sum-=heightVec[i];
            ansVec.pop_back();
            isVisited[i] = 0;
        }
        
    }
    
}


int main(){
    
    
    for(int i = 0; i<9; i++){
        int h;
        cin>>h;
        heightVec.push_back(h);
    }
    
    sort(heightVec.begin(), heightVec.end());
    
    Func(0, 7);
    
    for(int i = 0; i<7; i++){
        cout << ansVec[i] << "\n";
    }
    
    
    return 0;
}
