//
//  문자열_BF1110_더하기사이클.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/11.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


int main(){
    
    int num, num1, num2;
    cin >> num;

    
    int ans = 0;
    
    if(num<10) {
        num1 = 0;
        num2 = num;
    }
    else{
        num1 = num/10;
        num2 = num-num1*10;
    }
    
    
    
    while(1){
        ans+=1;
       
        int sum = num1 + num2;
        cout << "sum : " << sum << endl;
        if(sum>9){
            int q = sum/10;
            sum = sum-q*10;
        }
        
        int newNum = num2*10 + sum;
        cout << ans <<  " : " << newNum << endl;
        if(newNum==num) {
            break;
        }
        else{
            num1 = newNum/10;
            num2 = newNum - num1*10;
        }
        
    }
        
    cout << ans;
        
        
    
    return 0;
}
