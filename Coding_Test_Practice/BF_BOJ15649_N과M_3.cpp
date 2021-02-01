
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
bool isVisited[9]={0,};
vector<int> vec;

void DFS(int toPick){
    
    if(toPick==0){
        for(int i = 0; i<vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i<=N; i++){
        
       
        //if(isVisited[i]==0){
      //      isVisited[i] = 1;
            vec.push_back(i);
            DFS(toPick-1);
            vec.pop_back();
      //      isVisited[i] = 0;
            
        //}
    }
}

int main(){
    

    cin >> N >> M;

    DFS(M);
    
}
