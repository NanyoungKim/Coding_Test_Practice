#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N, M;

int map[4][4];
int chk[4][4];

int maxi = 0;

int cal(){
    
    int retSum = 0;
    int mulTen = 0;
    
    //가로 먼저 검사
    for(int r = 0; r<N; r++){
        for(int c = 0; c<M; c++){
            if(chk[r][c]==1){
                mulTen *= 10;
                mulTen += map[r][c];
            }
            else{
                retSum += mulTen;
                mulTen = 0;
            }
           
        }
        //행 끝남
        retSum += mulTen;   //마지막 열이 1이면 못 더한채로 끝나므로 더해줌. 0으로 끝난 경우엔 mulTen=0이라 더해도 상관 없음
        mulTen = 0;
        
        
    }
    
    mulTen = 0;
    //세로 검사
    for(int c = 0; c<M; c++){
        for(int r = 0; r<N; r++){
            
            if(chk[r][c] == 0){
                mulTen *= 10;
                mulTen += map[r][c];
            }
            else{
                retSum += mulTen;
                mulTen = 0;
            }
        }
        
        retSum += mulTen;
        mulTen = 0;
    }
    
    
    return retSum;
}

void dfs(){
    
    int sum = cal();
    if(maxi<sum) {
        maxi = sum;
    }
    
    
    for(int i = 0; i<N; i++){
         for(int j = 0; j<M; j++){
             
             if(chk[i][j]==0){
                 chk[i][j] = 1;
                 dfs();
                 chk[i][j] = 0;
             }
             
             
         }
    }
    
}




int main(){
   
    
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            map[i][j] = 0;
            chk[i][j] = 0;
        }
    }
    
    
    cin >> N >> M;  //세로 가로
    string s;
    for(int i = 0; i<N; i++){

        cin >> s;
        for(int j = 0; j<M; j++){
            map[i][j] = s[j] - '0';
        }
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << map[i][j];
            
        }cout << endl;
    }
 
    dfs();
    
    cout << maxi;
    
    
    return 0;
}
