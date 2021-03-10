//21.03.10
//next가 배열 범위 넘어가면 dr[],dc[]의 인덱스 증가
//top, right, bottom, left 순서로 칸 이동시킴
//(시계 반대방향으로 전진해야하므로 dr,dc의 인덱스는 오,아,왼,위 순서)

#include <iostream>
#include <algorithm>


using namespace std;

int map[301][301];
int N,M,R;

//오, 아, 왼, 위
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void rotate(int start, int len){
    
    int r = R%len;
    for(int i = 0; i<r; i++){   //r칸 전진
        
        int startVal = map[start][start];
        int r = start;
        int c = start;
        
        int k = 0;
        while(k<4){
            
            int nr = r + dr[k];     //map[nr][nc]는 옮길 대상임 (map[r][c]로 옮겨야 함)
            int nc = c + dc[k];
            
            if(nr==start && nc==start) break;
            if(start<=nr && nr<N-start && start<=nc && nc<M-start){
                
                //차례로 시계 반대방향으로 옮김
                map[r][c] = map[nr][nc];
                r = nr;
                c = nc;
                
            }
            else{       //다음에 옮길 칸이 배열 범위 넘어가버리면 해당 라인은 다 옮긴거라서 k 증가
                k++;
            }
        }
        map[start+1][start] = startVal; //처음에 시작지점 빼놨던거 마지막에 빈 자리에 넣어줌.
        
    }

    
}


int main(){
    
    cin >> N >> M >> R;
        
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    int cnt = min(N,M)/2;       //  박스 수


    int n=N, m=M;
    
    for(int i = 0; i<cnt; i++){ //반복문 1번에 / 박스 1개가 R만큼 전진함
            //시작 지점
        rotate(i, 2*n + 2*m -4);
        n-=2;
        m-=2;
        
    }
    
    
    
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << map[i][j] << " ";
        }cout <<"\n";
    }
    
    
    
    return 0;
}
