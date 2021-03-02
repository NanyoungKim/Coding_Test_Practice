#include <iostream>

using namespace std;

int map[25][25];
int visited[25][25];

//위 오 아 왼
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int N;
void dfs(int r, int c, int cnt){
    
    
    
    
    for(int i = 0; i<4; i++){
        
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr>=N || nr<0 || nc>=N || nc<0) continue;
        
        if(visited[nr][nc]==0 && map[nr][nc]==1){
            
            visited[nr][nc] = 1;
            dfs(nr,nc, cnt+1);
            visited[nr][nc] = 0;
            
        }
    }
 
}




int main(){
    
    int res=0;
    
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }
    
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if(map[i][j]==1 && visited[i][j]==0){
                visited[i][j] = 1;
                dfs(i,j, 0);
                visited[i][j] = 0;
                res++;
            }
        }
    }
    
    cout << cnt;
    
    
    return 0;
}
