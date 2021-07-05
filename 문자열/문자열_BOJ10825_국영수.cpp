//
//  문자열_BOJ10825_국영수.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/05/07.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Student{
  
public:
    string name;
    int g1, g2, g3;
    Student(string _name, int _g1, int _g2, int _g3){
        name = _name;
        g1 = _g1;
        g2 = _g2;
        g3 = _g3;
    }
    
};

bool cmp(Student std1, Student std2){
    if(std1.g1== std2.g1){
        if(std1.g2==std2.g2){
            if(std1.g3==std2.g3){       //수학도 같으면
                return std1.name.compare(std2.name) < 0;    //사전 순
            }
            //영어도 같으면 수학 감소하는 순서
            return std1.g3 > std2.g3;
        }
        //국어 같으면 영어 증가하는 순서
        return std1.g2 < std2.g2;
    }
    //국어 성적 다르면 국어 감소하는 순서
    return std1.g1 > std2.g1;
}

vector<Student> stdVec;
int main(){
    
    int N; cin >> N;
    for(int i = 0; i<N; i++){
        string n;
        int g1, g2, g3;
        cin >> n >> g1 >> g2 >> g3;
        Student std = Student(n, g1, g2, g3);
        stdVec.push_back(std);
    }
    
    sort(stdVec.begin(), stdVec.end(), cmp);
    
    for(int i = 0; i<stdVec.size(); i++){
        cout << stdVec[i].name <<"\n";
    }
    
    return 0;
}
