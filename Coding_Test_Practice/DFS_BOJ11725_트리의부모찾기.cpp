#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define ROOT 1
vector<int> connect[100001];
int parent[100001]={0};
int visited[100001]={0};
int N;
bool res;

void printAns(){
    for(int i=2; i<=N; i++){
        cout<<parent[i] << endl;
    }
    cout <<endl;
}


void DFS(int start){
    
    
    for(int i=0; i<connect[start].size(); i++){
        
        int next=connect[start][i];
        if(visited[next]==0){
            parent[next]=start;
            visited[next]=1;
            DFS(next);
        }
        
        
    }
    
}





int main(){
 
    cin>>N;
    
    for(int i=0; i<N-1; i++){
        int a,b;
        cin >> a >> b;
        connect[a].push_back(b);        //양방향으로 연결
        connect[b].push_back(a);
    }
    
    
    visited[ROOT]=1;
    
    int n = N/2 + 1;
    for(int i=1; i<=n; i++){
        DFS(i);
       // printAns();
    }
    
    
    
    
     for(int i=2; i<=N; i++){
         cout<<parent[i] << endl;
     }
    return 0;
}
