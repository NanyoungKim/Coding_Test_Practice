//
//  완전탐색_수영장(test).cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/04.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>

using namespace std;

int price[4] = {0,};
int dayofMonth[13] = {0,};
int dayandMonth[13] = {0,};

int d[13] = {0,};






int main(){
    
    int T;
    cin >> T;
    
    while(T--){
        
        for(int i = 0; i < 4; i++){
            cin >> price[i];
        }
        
        for(int i = 1; i<13; i++){
            cin >> dayofMonth[i];
        }
        
        
        for(int i = 1; i<13; i++){
            
            if(dayofMonth[i] != 0){
                if(dayofMonth[i]*price[0] < price[1]){
                    dayandMonth[i] =dayofMonth[i]*price[0];
                }
                else{
                    dayandMonth[i] = price[1];
                }
            }
            else{
                dayandMonth[i] = 0;
            }
        }
        
        
        
        for(int i = 1; i<13; i++){
            //i월까지의 최소 금액
            d[i] = d[i-1] + dayandMonth[i];         //1개뤌권 사용
            if(i>=3){
                if(d[i] > d[i-3] + price[2]){
                    d[i] = d[i-3] + price[2];
                }
                
                
            }
            
        }
        
        
        
        if(d[12] > price[3]){
            d[12] = price[3];
        }
        
        
        
    }
    
    
    return 0;
}
