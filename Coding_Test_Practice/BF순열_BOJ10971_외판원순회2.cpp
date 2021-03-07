#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int map[11][11];

int N;

bool isConnect(){
    
    bool ret = false;
    for(int i = 0; i<N-1; i++){
        if(map[vec[i]][vec[i+1]]!=0){
            ret = true;
        }
        else{
            ret = false;
            break;
        }
    }
    if(map[vec[N-1]][vec[0]]==0){
        ret = false;
    }
    
    return ret;
}



int main(){
    
    for(int i = 0; i<=10; i++){
        for(int j = 0; j<=10; j++){
            map[i][j] = 0;
        }
    }
    
    cin>> N;
    for(int i = 1; i<=N; i++){
        vec.push_back(i);     //1~N push
        
        for(int j = 1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    
    int sum;
    int mini = 10000000;
    
    do{
        //vec : 1 2 3 4 ,,, 4 3 2 1
        sum = 0;
        
        if(isConnect()){
            
            for(int i = 0; i<N-1; i++){
                sum += map[vec[i]][vec[i+1]];
            }
            sum+=map[vec[N-1]][vec[0]];
            if(mini > sum) {mini = sum;}
            
        }
        
    }while(next_permutation(vec.begin(), vec.end()));
    
    
    cout << mini;
    
    return 0;
}

