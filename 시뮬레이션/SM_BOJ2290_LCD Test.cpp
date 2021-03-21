//
//  SM_BOJ2290_LCD Test.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/21.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void printSpace(int s){     //가로 길이 s+2, 공백만 출력
    for(int i = 0; i<s+2; i++){ printf(" "); }
}
void printHorizon(int s){   //가로 길이 s+2, 양 옆만 공백, 가운데는 -로 채움
    printf(" ");
    for(int i = 0; i<s; i++){printf("-");}
    printf(" ");
}

void printVerRight(int s){  //가로 길이 s+2, 오른쪽 마지막에 |출력
    for(int i = 0; i<s+1; i++){printf(" ");}
    printf("|");
}
void printVerLeft(int s){   //가로 길이 s+2, 왼쪽 처음에 |출력
    printf("|");
    for(int i = 0; i<s+1; i++){printf(" ");}
}
void printVerBoth(int s){   //양쪽 공백, 가운데 s만큼 |
    printf("|");
    for(int i = 0; i<s; i++){printf(" ");}
    printf("|");
}


void printOne(int s, int row){
    
    if(row==1 || row==s+2 || row==2*s+3){ printSpace(s); }
    else{ printVerRight(s);}
}
void printTwo(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s); }
    else if(2<=row && row<=s+1){ printVerRight(s); }
    else{ printVerLeft(s);}
}
void printThree(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s);}
    else{ printVerRight(s); }
}
void printFour(int s, int row){
    if(row==1 || row==2*s+3){ printSpace(s);}
    else if(row==s+2){ printHorizon(s); }
    else if(2<=row && row<=s+1){ printVerBoth(s); }
    else{ printVerRight(s); }
}
void printFive(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s); }
    else if(2<=row && row<=s+1){ printVerLeft(s); }
    else{ printVerRight(s); }
}
void printSix(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s); }
    else if(2<=row && row<=s+1){ printVerLeft(s); }
    else{ printVerBoth(s); }
}
void printSeven(int s, int row){
    if(row==1){ printHorizon(s); }
    else if(row==s+2 || row==2*s+3){ printSpace(s); }
    else{  printVerRight(s); }
}
void printEight(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s); }
    else{ printVerBoth(s); }
}
void printNine(int s, int row){
    if(row==1 || row==s+2 || row==2*s+3){ printHorizon(s); }
    else if(2<=row && row<=s+1){ printVerBoth(s); }
    else{ printVerRight(s); }
}
void printZero(int s, int row){
    if(row==1 || row==2*s+3){ printHorizon(s); }
    else if(row==s+2){ printSpace(s); }
    else{ printVerBoth(s); }
}

int main(){
    
    int s,n;
    cin >> s >> n;
    int height = 2*s + 3;
    
    string N = to_string(n);
    
    for(int row=1; row<=height; row++){
        for(int i = 0; i<N.length(); i++){
        
            if(N[i]=='1'){ printOne(s, row); }
            else if(N[i]=='2'){ printTwo(s, row); }
            else if(N[i]=='3'){ printThree(s, row); }
            else if(N[i]=='4'){ printFour(s, row); }
            else if(N[i]=='5'){ printFive(s, row); }
            else if(N[i]=='6'){ printSix(s, row); }
            else if(N[i]=='7'){ printSeven(s, row); }
            else if(N[i]=='8'){ printEight(s, row); }
            else if(N[i]=='9'){ printNine(s, row); }
            else if(N[i]=='0'){ printZero(s, row); }
            
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
