#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int visited[10000] = {0};

vector<string> res;

bool DFS(string start, vector<vector<string>> tickets, int chkcnt){
 
    if(chkcnt==tickets.size()) return true;        //1-1) 탐색 다 끝나면 true 리턴해서
   
   for(int i = 0; i<tickets.size(); i++){
       if(visited[i]==0 && start == tickets[i][0]){
           visited[i] = 1;
           res.push_back(tickets[i][1]);
           bool resbool = DFS(tickets[i][1], tickets, chkcnt+1);
           if(resbool) return true;                //1-2) 더 이상 아래로 내려가지 않고 차례로 빠져나옴
           
           visited[i] = 0;                        //2-2) false 리턴됐으면 이 라인으로 내려오게 됨
       }
   }
    res.pop_back();    //길 끊겨서 항공권 다 탐색해도 이을게 없으면 마지막에 연결된 곳 pop
    return false;    //2-1) false 리턴해서 길 끊겼음을 알림
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());

    string start = "ICN";
    res.push_back(start);

    DFS(start, tickets, 0);
    answer = res;
       
    return answer;
}


int main(){
    
    vector<vector<string>> strVec;
    strVec = {
        {"ICN","SFO"},
        {"ICN","ATL"},
        {"SFO","ATL"},
        {"ATL","ICN"},
        {"ATL","SFO"}
        
    };
    vector<string> vec = solution(strVec);
    cout << "답 : ";
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] <<  " ";
    }
    return 0;
}
