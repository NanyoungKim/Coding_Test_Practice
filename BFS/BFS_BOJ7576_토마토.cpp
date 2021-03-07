#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int map[1000][1000];
int fromStart[1000][1000];

int M;  //가로 col
int N;  //세로 row
int nr, nc;
int start = 0, minu=0;
int r, c;

//위 오 아 왼
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int>> que;

void BFS(){
    
    while(!que.empty()){
   
        r = que.front().first;
        c = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++){
            
            nr = r + dr[i];
            nc = c + dc[i];
            
            if(nr<0 || nr >=N || nc<0 || nc >=M || map[nr][nc]==-1) continue;    //map -1이면 토마토 없음
            
            if(fromStart[nr][nc]==0 && map[nr][nc]==0){ //방문 안 했고 안 익은 토마토 있으면
                fromStart[nr][nc] = fromStart[r][c]+1;
                que.push(make_pair(nr,nc));
            }
        }
    }
}


int main(){
    
    cin >> M >> N;
    
    for(int i = 0 ;i <N; i++){
        for(int j = 0; j<M; j++){
            fromStart[i][j] = 0;        //visit 여부 & 해당 칸 토마토가 익기까지 day 수 저장
            
            cin >> map[i][j];
            if(map[i][j] == 1){
                que.push(make_pair(i,j));
                start++;                            //start는 맨 처음 익은 토마토 수
            }
            else if(map[i][j] == -1) minu++;        //minu는 토마토 없는 칸 수
        }
    }
    
    BFS();
    
    int chk = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(fromStart[i][j]!=0) chk++;            //방문 안한곳 있으면 -1 출력하기 위함
        }
    }
   
    if(chk+start+minu==M*N) cout << fromStart[r][c];
    else cout << -1;
    
    return 0;
}
