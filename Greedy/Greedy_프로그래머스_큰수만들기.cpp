//
////  Greedy_프로그래머스_큰수만들기.cpp
////  Coding_Test_Practice
////
////  Created by 김난영 on 2021/03/30.
////  Copyright © 2021 KimNanyoung. All rights reserved.
////
//
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string number, int k) {
//    string answer = "";
//     int numLen = number.length();      //주어진 수 길이
//
//       int p = numLen-k;    //p = 6     //제거하고 남은 수 길이
//       int a = numLen-(p-1);
//
//       int check = 0;
//
//       for(int i = 0; i< p; i++){
//           char m = number[0];
//           check = 0;
//           if(m =='9'){
//               answer.append("9");
//           }
//          else{
//
//           for(int j=0; j<a-1; j++){
//
//
//               if(m < number[j+1]){             //가장 큰 값과 그 인덱스 찾기
//                   m = number[j+1];
//                   check = j+1;//check = 2
//               }
//
//           }
//           string max(1,m);
//           answer.append(max);
//          }
//
//
//           for(int b=0; b<numLen-(check+1); b++){
//               number[b] = number[b+check+1];
//           }
//
//           numLen = numLen-(check+1);
//           if(numLen==0){
//              // char m2 = number[1];
//            //   string max2(1,m2);
//            //   answer.append(max2);
//               break;
//           }
//           a = numLen-p+i+2;
//       }
//      //  cout << answer << endl;
//
//    return answer;
//}
//
//
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> ansVec;
     int numLen = number.length();      //주어진 수 길이

    vector<char> vec;
    vector<char>::iterator iter;
    int p = numLen-k;    //p = 6     //제거하고 남은 수 길이
    int a = numLen-(p-1);

    for(int i = 0; i<numLen; i++){
        vec.push_back(number[i]);
    }
    
    for(int i = 0; i<k; i++){
        char maxi = vec[0];
        vector<char>::iterator maxIter = vec.begin();
        iter = vec.begin();
        
        if(maxi == '9'){
            vec.erase(vec.begin());
            ansVec.push_back(maxi);
        }
        else{
            for(iter = vec.begin(); iter!=vec.begin()+a; iter++){
                if(maxi<*iter) {
                    maxi = *iter;
                    maxIter = iter;
                }
            }
              
            vec.erase(maxIter);
            ansVec.push_back(maxi);
        }
        
        
    }
    
    for(int i = 0; i<ansVec.size(); i++){
        printf("%c ", ansVec[i]);
    }
    
    
    return answer;
}



int main(){
    
    solution("4177252841", 4);
    return 0;
}
