#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[2000] = {0};
vector<int> vecArr[2000];
bool flag = false;

void dfs(int start, int depth){
    
    visited[start] = 1;
    
    if(depth==4){
        flag = true;                //더 이상 dfs 실행 안 되게 함.
        cout << 1 << "\n";
        return;
    }
    
    for(int i = 0; i<vecArr[start].size(); i++){
        if(visited[vecArr[start][i]]==0 && !flag){        //위에서 flag=true 됐으면 조건문 실행 x
            dfs(vecArr[start][i], depth+1);                //타고 들어갈 때마다 depth 증가
        }
    }

    visited[start] = 0;
    
}




int main(){

    queue<int> que;
    
    int N,M;
    cin >> N >> M;
    
    int a, b;
    for(int i = 0; i<M; i++){            //관계 양 방향 연결 (벡터 배열 사용)
        cin >> a >> b;
        
        vecArr[a].push_back(b);
        vecArr[b].push_back(a);
        
    }
    
    
    for(int i = 0; i<N; i++){
        dfs(i,0);
    }
    
    if(!flag) cout << 0;                //다 탐색 했는데 깊이가 4 된 경우 없으면 0 출력.
    
    return 0;
}
