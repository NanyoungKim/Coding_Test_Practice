
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
int node1, node2;
int parent, child;

int parentArr[101] = {0};


vector<int> findParent(int child){
    
    vector<int> vec;
    int sum = 0;
    
    while(1){
            
        int parent = parentArr[child];
        if(parent == 0) {
            
            vec.push_back(child);    //루트노드
            vec.push_back(sum);     //그 루트노드까지 거슬러 올라간 길이(촌수)
            break;
        }                           //거슬러 올라가다 node2를 만나버리면
        else if(child==node2){
            vec.push_back(-1);
            vec.push_back(sum);
            break;
        }
        else{
            sum+=1;
            child = parent;
        }
    }
    return vec;
}



int main(){
    
    int answer = 0;
    
    cin>>n;
    cin>>node1 >> node2;
    cin>>m;

    for(int i = 0; i<m; i++){
        cin >> parent >> child;
        parentArr[child] = parent;
    }

    
    vector<int> ansVec1 = findParent(node1);
    vector<int> ansVec2 = findParent(node2);
    
    if(ansVec1[0]==-1){             //거슬러 올라가다가 만난
        answer = ansVec1[1];
    }
    else{
        if(ansVec1[0]!=ansVec2[0]){
            answer = -1;
        }
        else{
            answer = ansVec1[1] + ansVec2[1];
        }
    }
    

    cout << answer << endl;
  
    return 0;
}
