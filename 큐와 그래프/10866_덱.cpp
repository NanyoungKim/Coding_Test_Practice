#include <iostream>
#include <deque>
#include <string>

using namespace std;


int main(){
    
    
    int N;
    cin >> N;
    
    
    deque<int> dque;
    string str;
    int num, res;
    for(int i = 0; i<N; i++){
        
        cin >> str;
        
        if(str=="push_front"){
            cin >> num;
            dque.push_front(num);
        }
        else if(str=="push_back"){
            cin >> num;
            dque.push_back(num);
        }
                
        else if(str=="pop_front"){
            res = dque.empty() ? -1 : dque.front();
            cout << res <<"\n";
            if(!dque.empty()){dque.pop_front();}
        }
        else if(str=="pop_back"){
            res = dque.empty() ? -1 : dque.back();
            cout << res <<"\n";
            if(!dque.empty()){dque.pop_back();}
        }
        
        
        else if(str=="size"){
            cout << dque.size() << "\n";
        }
        else if(str=="empty"){
            res = dque.empty() ? 1 :  0 ;
            cout << res <<"\n";
        }
        else if(str=="front"){
            res = dque.empty() ? -1 : dque.front();
            cout << res << "\n";
        }
        else if(str=="back"){
            res = dque.empty() ? -1 : dque.back();
            cout << res << "\n";
        }
        
    }
    
    
    return 0;
}


