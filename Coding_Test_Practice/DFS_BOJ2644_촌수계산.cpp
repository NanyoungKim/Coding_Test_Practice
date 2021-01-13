
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


queue<int> que;
int fromStart[101];
vector<int> connected[101];     //연결된 노드들이 벡터에 저장되어 각 배열에 들어있음

int BFS(int start, int end){
    
    while(!que.empty()){
        
        int x = que.front();
        que.pop();
        
        if(x==end){                     //타겟 노드 찾으면 시작노드부터 그 노드까지 거리 리턴
            return fromStart[x];
        }
        
        else{
            for(int i = 0; i<connected[x].size(); i++){
                int next = connected[x][i];
                
                if(fromStart[next]==0){ //아직 방문 안한 곳
                    que.push(next);
                    fromStart[next] = fromStart[x] + 1;
                }
            }
        }
    }
    
    return -1;

}


int main(){
    
    int answer = 0;
    int n,m;
    int node1, node2;
    int parent, child;

    
    cin >> n >> node1 >> node2 >> m;

    
    for(int i = 0; i<m; i++){
        cin >> parent >> child;
        connected[parent].push_back(child);     //양방향 연결
        connected[child].push_back(parent);

    }
    
    que.push(node1);
    
    answer = BFS(node1,node2);
    
    
    
    cout << answer << endl;
  
    return 0;
}
