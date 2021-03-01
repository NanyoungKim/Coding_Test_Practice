#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main(){
    
    
    int N;
    cin >> N;
    
    
    queue<int> que;
    string str;
    int num, res;
    for(int i = 0; i<N; i++){
        
        cin >> str;
        
        if(str=="push"){
            cin >> num;
            que.push(num);
        }
        if(str=="pop"){
            if(que.empty()){
                cout << "-1\n";
            }
            else{
                cout << que.front() << "\n";
                que.pop();
            }
        }
        else if(str=="size"){
            cout << que.size() << "\n";
        }
        else if(str=="empty"){
            res = que.empty() ? 1 :  0 ;
            cout << res <<"\n";
        }
        else if(str=="front"){
            res = que.empty() ? -1 : que.front();
            cout << res << "\n";
        }
        else if(str=="back"){
            res = que.empty() ? -1 : que.back();
            cout << res << "\n";
        }
        
    }
    
    
    return 0;
}


