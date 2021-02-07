#include <iostream>
#include <vector>


using namespace std;


vector<char> cVec;
int k;
vector<int> gVec;
vector<int> lVec;
vector<int> pickVec;

int ans;
int visited[10] = {0};

bool flag = true;


bool chk(vector<int> numVec){
    for(int i = 0; i<k; i++){
        if(cVec[i]=='<' && numVec[i]>numVec[i+1]) return false;
        if(cVec[i]=='>' && numVec[i]<numVec[i+1]) return false;
    }
    return true;
}

void choiceNum(int toPick, vector<int> vec){
    
    
    if(toPick==0){
        
        if(chk(pickVec)){flag = false; return;}
        
    }
    
    
    for(int i = 0; i<vec.size(); i++){
        if(visited[i] == 0  && flag){
            visited[i] = 1;
            pickVec.push_back(vec[i]);
            choiceNum(toPick-1, vec);
            pickVec.pop_back();
            visited[i] = 0;
        }
        
    }
    
    
}




int main(){
    
    
   
    cin>>k;
    
    for(int i = 0; i<k; i++){
        char c;
        cin >> c;
        cVec.push_back(c);
    }
    
    
    
    for(int i = 0; i<10; i++){ gVec.push_back(i); } //0~9
    for(int i = 9; i>=0; i--){ lVec.push_back(i); } //9~0
    
    
    choiceNum(k+1, gVec);
    for(int i = 0; i<pickVec.size(); i++){
        cout << pickVec[i] ;
    }
    
    
    
    
    pickVec.clear();
    memset(visited, 0, sizeof(visited));        flag = true;
    
    
    
    
    
    choiceNum(k+1, lVec);
    for(int i = 0; i<pickVec.size(); i++){
        cout << pickVec[i] ;
    }
    
    return 0;
}
