#include <iostream>
#include <queue>
#include <vector>
#include <cstring>    //memset

using namespace std;

vector<int> vecArr[20001];

int visit[20001] = {0};
int group[20001] = {0};
int V,E;

void BFS(int start){
    queue<int> que;

    que.push(start);
    visit[start] = 1;
    group[start] = 1;
    int color = 1;
    
    
    while(!que.empty()){
        
        int sV = que.front();
        que.pop();

        if(group[sV]==1) color = 2;
        else if(group[sV]==2) color = 1;
        
        for(int i = 0; i<vecArr[sV].size(); i++){
            
            int nV = vecArr[sV][i];
            
            if(visit[nV]==0){
                que.push(nV);
                visit[nV] = 1;
                group[nV] = color;
                
            }
            
        }
    }

}


int main(){
    
    int T; cin >> T;
    
    for(int t=0; t<T; t++){

        cin >> V >> E;
        
        int e1,e2;
        for(int i = 0; i<E; i++){
            cin >> e1 >> e2;
            vecArr[e1].push_back(e2);
            vecArr[e2].push_back(e1);
        }
        
       
        for(int i = 1; i<=V; i++){
            if(visit[i]==0){
                BFS(i);
            }
        }
        
        bool chk = true;
        for(int i=1; i<=V; i++){
            for(int j = 0; j<vecArr[i].size(); j++){
                if(group[i]==group[vecArr[i][j]]){
                    chk=false;
                    break;
                }
            }
        }
       if(!chk) cout << "NO\n";
       else cout << "YES\n";
        
        
        for(int i = 0; i<=V; i++) vecArr[i].clear();
        memset(visit,0,sizeof(visit));
        memset(group,0,sizeof(group));
        
        
    }
    
    
    
    
    
    return 0;
}
