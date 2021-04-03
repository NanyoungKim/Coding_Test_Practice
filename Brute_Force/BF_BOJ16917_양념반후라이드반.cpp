//
//  BF_BOJ16917_양념반후라이드반.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/03.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//
//X,Y가 구입하는 "최소" 개수라는 것을 주의해야한다.
//즉, X,Y 개 이상 구입할 수 있는 것이다.
//반복문을 돌면서 반반으로 얼마나 구매해야하는지와 그때의 최소 가격을 구한다.

#include <iostream>

using namespace std;


int main(){
    
    
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    
    bool ischeapBanBan = A+B>2*C ? true : false;    //양념 + 후라이드 각각 사는게 더 싼지 체크
    
    long long mini = 10000000000, sum;
    if(ischeapBanBan){
        
        if(X>Y) {
           
            for(int i = Y; i<=X; i++){
                sum = 2*C*i + (X-i)*A;          //(X-i) : 반반 구매하고 더 구매해야 하는 양념 치킨 수
                if(sum<mini) {mini = sum;}
            }
        }
        else {
            for(int i = X; i<=Y; i++){
                sum = 2*C*i + (Y-i)*B;         //(Y-i) : 반반 구매하고 더 구매해야 하는 후라이드 치킨 수
                if(sum<mini) {mini = sum;}
            }
        }
        
    }
    else{
        mini  = A*X + B*Y;
    }
    
    cout << mini;
    return 0;
}
