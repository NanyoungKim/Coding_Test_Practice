#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> vec;
int visited[20] = {0};
int ans = 0;

vector<int> seqVec;


void search(int s, int idx){
    
    
    if(seqVec.size()>=1){
        
        int sum = 0;
        for(int i = 0; i<seqVec.size(); i++){
        //    cout << seqVec[i] << " ";
            sum+=seqVec[i];
        }
      //  cout << "\nsum: " << sum << "\n";
        if(sum==s) {ans++;}

    }
    
    for(int i = 0; i<vec.size(); i++){
        
        if(idx<i && visited[i]==0){
            visited[i] = 1;
            seqVec.push_back(vec[i]);
            search(s,i);
            seqVec.pop_back();
            visited[i] = 0;
        }
    }
}


int main(){
    
    cin >> N >> S;
    for(int i = 0; i<N; i++){
        int n;  cin>>n;
        vec.push_back(n);
    }
    
   // sort(vec.begin(), vec.end());
    
    //int mini = vec[0];
    search(S,-1);
    
    cout << ans;
    
    return 0;
}
