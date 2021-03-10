//21.03.10
//next가 배열 범위 넘어가면 dr[],dc[]의 인덱스 증가

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 101
using namespace std;

int map[101][101];
int map2[101][101];
int N,M,R;

//오, 아, 왼, 위
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void print(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            printf("%d ", map[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void init1(){
    
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            map[i][j] = 0;
        }
    }
}
void init2(){
    
    for(int i = 0; i<MAX; i++){
        for(int j = 0; j<MAX; j++){
            map2[i][j] = 0;
        }
    }
}


//상하 반전
void func1(){
    
    int tmp;
    for(int i = 0; i<N/2; i++){
        for(int j = 0; j<M; j++){
            tmp= map[N-1-i][j];
            map[N-1-i][j] = map[i][j];
            map[i][j] = tmp;
        }
    }

}

void func2(){
    int tmp;
    
    for(int i = 0; i<N; i++){
        for(int j=0; j<M/2; j++){
            tmp = map[i][M-1-j];
            map[i][M-1-j] = map[i][j];
            map[i][j] = tmp;
        }
    }

}

void func3(){
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            map2[j][N-1-i] = map[i][j];
        }
    }
    init1();
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            map[i][j] = map2[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
    
}

void func4(){
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            map2[M-1-j][i] = map[i][j];
        }
    }
    init1();
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            map[i][j] = map2[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
}

void func5(){
        
    //첫번째 그룹 임시저장
    for(int i = 0; i<N/2; i++){
        for(int j = 0; j<M/2; j++){
            map2[i][j] = map[i][j];
        }
    }
    //4->1
    for(int i = 0; i<N/2; i++){
        for(int j = 0; j<M/2; j++){
            map[i][j] = map[i+N/2][j];
        }
    }
    //3->4
    for(int i = N/2; i<N; i++){
        for(int j = 0; j<M/2; j++){
            map[i][j] = map[i][j+M/2];
        }
    }
    //2->3
    for(int i = N/2; i<N; i++){
        for(int j = M/2; j<M; j++){
            map[i][j] = map[i-N/2][j];
        }
    }
    //2->1
    for(int i=0; i<N/2; i++){
        for(int j = M/2; j<M; j++){
            map[i][j] = map2[i][j-M/2];
        }
    }
    init2();
    
    
}
void func6(){
    //첫번째 그룹 임시저장
    for(int i = 0; i<N/2; i++){
        for(int j = 0; j<M/2; j++){
            map2[i][j] = map[i][j];
        }
    }
    //2->1
    for(int i = 0; i<N/2; i++){
        for(int j = 0; j<M/2; j++){
            map[i][j] = map[i][j+M/2];
        }
    }
    //3->2
    for(int i = 0; i<N/2; i++){
        for(int j = M/2; j<M; j++){
            map[i][j] = map[i+N/2][j];
        }
    }
    //4->3
    for(int i = N/2; i<N; i++){
        for(int j = M/2; j<M; j++){
            map[i][j] = map[i][j-M/2];
        }
    }
    //4->1
    for(int i=N/2; i<N; i++){
        for(int j = 0; j<M/2; j++){
            map[i][j] = map2[i-N/2][j];
        }
    }
    init2();
}



int main(){
    
    cin >> N >> M >> R;
        
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }
 
    
    vector<int> numVec;
    string remainder; getline(cin, remainder);
    string strNum;
    getline(cin, strNum);
    
    for(int i = 0; i<strNum.length(); i++){
        if(i%2 == 0) numVec.push_back(strNum[i]-'0');
    }
    
    for(int i = 0; i<numVec.size(); i++){
        int num = numVec[i];
        init2();
        switch(num){
               case 1:
                   func1();
                   break;
               case 2:
                   func2();
                   break;
               case 3:
                   func3();
                   break;
               case 4:
                   func4();
                   break;
               case 5:
                   func5();
                   break;
               case 6:
                   func6();
                   break;
               deafult:
                   break;
           }
        //print();
    }
    
     for(int i = 0; i<N; i++){
         for(int j = 0; j<M; j++){
             printf("%d ", map[i][j]);
         }printf("\n");
     }
    
    
    return 0;
}
