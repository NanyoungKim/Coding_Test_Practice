#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int map[4][4]={0};

//위,오,아,왼
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

vector<int> nVec;
priority_queue<int> pque;
deque<int> dque;
set<int> ansVec;
bool flag=true;


void DFS(int r, int c, int toPick){
    
   
    if(toPick==0){
        int num = nVec[0]*1000000+nVec[1]*100000+nVec[2]*10000+nVec[3]*1000+nVec[4]*100+nVec[5]*10+nVec[6];
        
        ansVec.insert(num);
        return;
    }
    
    
    for(int i=0; i<4; i++){
        
        int nr=r+dr[i];
        int nc=c+dc[i];
        
        if(nr>=4 || nr<0 || nc>=4 || nc<0) continue;
        
        nVec.push_back(map[nr][nc]);    //next 지점이 범위 안에 들어오면 push
        DFS(nr,nc,toPick-1);
        nVec.pop_back();
    }
}

int main(){

    int T;
    cin >> T;
    
    int ans=0;
    for(int test_case = 1; test_case <= T; test_case++){
        
         for(int i=0; i<4; i++){
           for(int j=0; j<4; j++){
               cin>>map[i][j];
           }
         }
        
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                nVec.push_back(map[i][j]);          //첫 시작지점 넣음
                DFS(i,j,6);
                nVec.clear();
            }
        }
        
        cout << "#" << test_case << " " << ansVec.size() << "\n";
        
        ans=0;
        ansVec.clear();
        nVec.clear();
        
    }
    
    return 0;
}
