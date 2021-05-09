////
////  Programmers_SummerCoding_2.cpp
////  Coding_Test_Practice
////
////  Created by 김난영 on 2021/05/09.
////  Copyright © 2021 KimNanyoung. All rights reserved.
////
//
//#include <string>
//#include <vector>
//#include <utility>
//#include <algorithm>
//
//using namespace std;
//                                                  //ff fs, sf, ss
//vector<pair<pair<int,int>, pair<int,int>>> guest;//id, r, 기존t , 바뀐 t
//
//bool cmp(pair<pair<int,int>, pair<int,int>> p1, pair<pair<int,int>, pair<int,int>> p2){
//
//    if(p1.second.second==p2.second.second){     //바뀐 t ==
//
//        if(p1.first.second == p2.first.second){     //r ==
//
//            if(p1.second.first == p2.second.first){ //기존 t
//                return p1.first.first < p2.first.first;
//            }
//            else{
//                return p1.second.first < p2.second.first;
//            }
//        }
//        else{
//            return p1.first.second < p2.first.second;
//        }
//
//    }
//    else{
//        return p1.second.second < p2.second.second;
//    }
//
//
//}
//
//vector<int> solution(vector<int> t, vector<int> r) {
//    vector<int> answer;
//
//    for(int i = 0; i<t.size(); i++){
//        guest.push_back(make_pair(make_pair(i, r[i]), make_pair(t[i], t[i])));
//    }
//
//    while(answer.size()<t.size()){
//
//        sort(guest.begin(), guest.end(), cmp);
//
//        answer.push_back(guest[0].first.first); //id
//
//
//        //t 증가
//        for(int k = 1; k<guest.size(); k++){    //id, r , 기존 t, 바뀐 t
//            if(guest[0].second.second == guest[k].second.second){ //시간 같은데 우선 순위 밀려서 리프트 못 탄 사람들 시간 증가
//                guest[k].second.second = guest[k].second.first + 1;
//            }
//            else break;
//        }
//
//        guest.erase(guest.begin());
//
//
//    }
//
//
//    return answer;
//}
//
//
//int main(){
//
//
//    return 0;
//}



#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

bool cmp(pair<int, pair<int,int>> p1, pair<int, pair<int,int>> p2){
    if(p1.second.second == p2.second.second){
        return p1.first < p2.first;
    }
    else{
        return p1.second.second < p2.second.second;
    }
}

vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer;
    
    int tcnt=-1;
    vector<pair<int, pair<int,int>>> cur;  //id, t, r 현재 탑승장에 대기 중인 승객
    
    while(answer.size() < t.size()){
        tcnt+=1;
      
        for(int i = 0; i<t.size(); i++){
            if(tcnt== t[i]){
                cur.push_back(make_pair(i, make_pair(t[i],r[i])));
            }
        }
        for(int i = 0; i<cur.size(); i++){
            cout << cur[i].first << " ";
        }cout << endl;
        
        sort(cur.begin(), cur.end(), cmp);
        answer.push_back(cur[0].first);
        cur.erase(cur.begin());
        
    }
    
    
    return answer;
}



int main(){
    
    
    return 0;
    vector<int> t = {7,6,8,1};
    vector<int> r = {0,1,2,3};
    vector<int> ans = solution(t, r);
    
//    for(int i = 0; i<ans.size(); i++){
//        cout <<
//    }
}
