#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

char map[50][50];



int N;
int candy = 0;
int resMax = 0;

void countRow(){
    
    char color=map[0][0];
    
    for(int i = 0; i<N; i++){
        int cnt=1;

        for(int j = 0; j<N-1; j++){

            if(map[i][j]==map[i][j+1]){
                color = map[i][j];
                cnt++;
            }
            else{
                color=map[i][j+1];
                resMax=max(resMax,cnt);
                cnt=1;
            }
        }
        resMax=max(resMax,cnt);
    }
}

void countCol(){
    
    char color=map[0][0];
    
    for(int j = 0; j<N; j++){
        int cnt=1;

        for(int i = 0; i<N-1; i++){
            
            if(map[i][j]==map[i+1][j]){
                color = map[i][j];
                cnt++;
            }
            else{
            color=map[i][j+1];
            resMax=max(resMax,cnt);

            cnt=1;
            }
        }
        resMax=max(resMax,cnt);
    }
}

void swapFunc(int r,int c,int nr,int nc){
    int tmp = map[r][c];
    map[r][c] = map[nr][nc];
    map[nr][nc] = tmp;
}


void solve(int r, int c){

    //행 검사
    countRow();
    
    //열검사
    countCol();
    
}



int main(){
    
    
    cin >> N;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N-1; j++){
     
            swapFunc(i,j,i,j+1);
            solve(i,j);             //가로 스왑
            swapFunc(i,j,i,j+1);
 
            
        }
    }
    
    
   for(int j = 0; j<N; j++){
       for(int i = 0; i<N-1; i++){
    
           swapFunc(i,j,i+1,j);
           solve(i,j);               //세로 스왑
           swapFunc(i,j,i+1,j);
       }
   }

    
    cout<<resMax<<"\n";
    
    
    return 0;
}

