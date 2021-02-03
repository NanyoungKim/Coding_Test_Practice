#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alpha;
vector<char> ansVec;
int visited[15] = {0};

bool chk(){
    int cntV = 0;   //모음
    int cntC = 0;   //자음
    for(int i = 0; i<ansVec.size(); i++){
        if(ansVec[i]=='a' || ansVec[i]=='e' || ansVec[i]=='i' || ansVec[i]=='o' || ansVec[i]=='u') {cntV++;}
        else cntC++;
    }
    if(cntV>=1 && cntC>=2) return true;
    else return false;

}



void dfs(int toPick, char c){
    
    if(toPick==0){
        if(chk()){
            for(int i = 0; i<ansVec.size(); i++){
                cout << ansVec[i];
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i = 0; i<alpha.size(); i++){
        
        if(visited[i]==0 && c<=alpha[i]){
            visited[i] = 1;
            ansVec.push_back(alpha[i]);
            dfs(toPick-1, alpha[i]);
            ansVec.pop_back();
            visited[i] = 0;
            
        }
        
    }
    
}
int main(){
    
    int L,C;
    cin >> L >> C;
    
    for(int i = 0; i<C; i++){
        char c; cin >> c;
        alpha.push_back(c);
    }
    
    sort(alpha.begin(), alpha.end());
    dfs(L, 'a');
    
    
    return 0;
}
