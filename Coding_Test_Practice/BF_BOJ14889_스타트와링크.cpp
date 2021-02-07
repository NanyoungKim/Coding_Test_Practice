#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int map[21][21];
int visited[21] = {0};
int num;

vector<int> start;
vector<int> link;

int chk[11] = {0};

vector<int> vec;
vector<int> sumVec;
int ans1 = 0;
int ans2= 0;
int ans = 100000000;


vector<int> sSum;
void sumFunc(int toPick, vector<int> vec){
    
    if(toPick==0){
        
        int sum =  map[sumVec[0]][sumVec[1]] + map[sumVec[1]][sumVec[0]];
        sSum.push_back(sum);
        return;
    }
    
    for(int i = 0; i<vec.size(); i++){
        if(chk[i] ==0){
            chk[i] = 1;
            sumVec.push_back(vec[i]);
            sumFunc(toPick-1, vec);
            sumVec.pop_back();
            chk[i] = 0;
            
        }
    }
    
    
}


void choiceFunc(int toPick, int num){
    
    
    if(toPick==0){
        ans1 = 0; ans2 = 0;
        link.clear();

        for(int j = 1; j<=N; j++){
            if(visited[j]==0) {
                link.push_back(j);
            }
        }
        
        
        //test
        cout << "start: " ;
        for(int p = 0; p<start.size(); p++){cout << start[p] << " ";}
        cout << "\nlink: " ;
        for(int p = 0; p<link.size(); p++){cout << link[p] << " ";}
        cout << "\n" ;
        
        
        
        
        sumFunc(2, start);
        for(int i = 0; i<sSum.size(); i++){
            ans1+=sSum[i];
        }
        sSum.clear();
        sumFunc(2, link);
        for(int i = 0; i<sSum.size(); i++){
            ans2+=sSum[i];
        }
        sSum.clear();
        
        cout << ans1 << " " << ans2 << endl;
        
        if(ans1<ans2){
            int tmp=ans1;
            ans1=ans2;
            ans2=tmp;
        }
        
        if(ans1-ans2 < ans){ans = ans1-ans2;}
        
        cout << ans << endl;
        
        //for(int k = 0; k<11; k++){chk[k] = 0;}
        memset(chk, 0, sizeof(chk));
        
        return;
        
    }
    
    for(int i = 1; i<=N; i++){
        
        if(visited[i]==0 && num<i){
            visited[i] = 1;
            start.push_back(i);
            choiceFunc(toPick-1, i);
            start.pop_back();
            visited[i] = 0;
            
        }
    }
    
}



int main(){
    
    cin >> N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    num = (N*(N-1)) / 4;
    
    choiceFunc(N/2, 0);
    
    cout << ans/2 ;
    
    return 0;
}
