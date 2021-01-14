#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//11부터 시계 반대방향
int dr[8] = {-2,-1,1,2,2,1,-1,-2};
int dc[8] = {-1,-2,-2,-1,1,2,2,1};

queue<pair<int,int>> que;
int I, cur1, cur2, next1, next2, cnt;

int fromStart[300][300];

void settingMap(){
    for(int i = 0; i<I; i++){
        for(int j = 0; j<I; j++){  fromStart[i][j] = 0;}
    }
}


void printMap(){
    
    for(int i = 0; i<I; i++){
        for(int j = 0; j<I; j++){
            cout << fromStart[i][j] << " ";
            
        } cout << endl;
    }
    cout << endl;
}



int BFS(){
    int res = 0;
    
    while(!que.empty()){
       // printMap();
        
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        if(r==next1 && c==next2){           //도착지점이면 그 지점까지의 거리 리턴
            res = fromStart[r][c];
            break;
        }

        for(int i = 0; i<8; i++){
                
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr>=I || nr<0 || nc>=I || nc<0){     //범위 벗어나면 패스
                continue;
            }
            if(fromStart[nr][nc]==0){               //옮길 곳이 범위 안에 들어오고 방문 안한 곳이면
                fromStart[nr][nc] = fromStart[r][c] + 1;
                que.push(make_pair(nr, nc));
            
            }
        }
   
    }
    return res;
}


int main(){
    
    int TC;
    cin >> TC;
    for(int t = 0; t<TC; t++){
        
        settingMap();
        cin >> I >> cur1 >> cur2 >> next1 >> next2;
        
        que.push(make_pair(cur1,cur2));
        cout  << BFS() << endl;
        que = queue<pair<int,int>>();
    }
    
    return 0;
}
