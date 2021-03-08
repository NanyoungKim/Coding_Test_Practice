#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define MAX 101

int N,M;
int map[MAX][MAX];
queue<pair<int,int>> que;

int cntWall[MAX][MAX];

//위 오 아 왼
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void BFS(){
    
    while(!que.empty()){

        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr<1 || nr>N || nc<1 || nc>M) continue;        //범위 체크
    
            if(map[nr][nc] == 1){        //다음 칸이 벽일 때
                
                if(cntWall[nr][nc] > cntWall[r][c]+1){        //갱신 조건
                    cntWall[nr][nc] =cntWall[r][c]+1;
                     que.push(make_pair(nr,nc));
                }
                
            }
            else{                        //다음 칸이 방일 때
                if(cntWall[nr][nc]>cntWall[r][c]){            //갱신 조건
                    cntWall[nr][nc] = cntWall[r][c];
                    que.push(make_pair(nr,nc));
                }
            }
        }
    }
}

int main(){

    cin >> M >> N;
    string str;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cntWall[i][j] = 1000;            //최대 값으로 초기 설정
        }
    }
    
    for(int i = 1; i<=N; i++){
        cin >> str;
        for(int j = 1; j<=str.length(); j++){
            map[i][j] = str[j-1]-'0';
        }
    }
    //입력받을 때 동일한 방법
    /* for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            scanf( "%1d", &map[i][j] );
        }
    }*/
   
    
    que.push(make_pair(1,1));
    cntWall[1][1] = 0;          //항상 뚫려 있다고 했으므로 0으로 초기 설정 가능
    
    BFS();
    
    cout << cntWall[N][M];
   
    
    return 0;
}
