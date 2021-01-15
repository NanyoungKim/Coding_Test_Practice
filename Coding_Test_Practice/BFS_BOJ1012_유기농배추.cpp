#include <iostream>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

    
int N,M,K; //세로,가로,배추개수
int map[50][50];
int visited[50][50];

        //좌, 우, 상, 하
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};

queue<pair<int,int>> que;

void settingMap(){
    memset(visited,0,sizeof(visited));
    memset(map,0,sizeof(map));
   
    que = queue<pair<int,int>>();
            
}

void BFS(int rr, int cc){

    
    que.push(make_pair(rr,cc));
    
    while(!que.empty()){

        int r = que.front().first;
        int c = que.front().second;
        visited[r][c]=1;
        que.pop();
        
        for(int i=0; i<4; i++){
            
            int nr=r+dr[i];
            int nc=c+dc[i];
            
            if(nr>=N || nr<0 || nc>=M || nc<0){     //범위 벗어나면 패스
                continue;
            }
            
            if(map[nr][nc]==1 && visited[nr][nc]==0){
                visited[nr][nc]=1;
                que.push(make_pair(nr, nc));
            }

        }
        
    }
    
}


int main(){

    int TC,ans;
    cin >> TC;
    for(int t = 0; t<TC; t++){
        
        settingMap();   //초기화

        ans=0;
        
        cin>>M>>N>>K;
        for(int i = 0; i<K; i++){
            
            int r,c;
            cin>>c>>r;
            map[r][c] = 1;
        }
        
        
    
        
        for(int i=0; i<N; i++){ //세로
        
            for(int j=0; j<M; j++){//가로
                
                if(map[i][j]==1 && visited[i][j]==0){
                    
                    BFS(i,j);
                    ans+=1;
                    
                }
                
            }
        }
        
        
        cout <<ans << endl;
        
        
        
    }
    

    
    return 0;
    
}
