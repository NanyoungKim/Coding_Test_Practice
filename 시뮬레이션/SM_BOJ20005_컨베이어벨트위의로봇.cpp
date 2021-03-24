//
//  SM_BOJ20005_컨베이어벨트위의로봇.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/03/24.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

//내구도는 1~2N, 로봇은 1~N 도는것에 주의
//1에서 로봇 올라오고 N에서 무조건 내려야 함.


#include <iostream>
#include <utility>

using namespace std;

int beltArr[201] = {0};
pair<int,bool> isRobot[101]; //몇번째인지, 로봇 있는지여부
int N,K;

bool cntZero(){            //내구도 0인 곳이 K개 이상이면 true 리턴
    
    int cnt = 0;
    bool res = false;
    for(int i = 1; i<=2*N; i++){
        if(beltArr[i]==0){
            cnt++;
        }
        if(cnt>=K) {
            res = true;
            break;
        }
    }
    return res;
    
}

int findFirstRobot(){        //1~N 칸에서 가장 먼저 들어간 로봇 찾기
    
    for(int i = N; i>=1; i--){
        if(isRobot[i].second==true){
            return i;
        }
    }
    return 0;
}

//2번 : 로봇 한칸 전진 : 먼저 올라간 로봇부터 / 이동 가능하면(로봇 없고, 내구도 1이상) / 로봇&내구도 바꿈
void shiftRobot(){
    
    
    int minIdx = findFirstRobot();

    if(minIdx!=0){
        for(int i = minIdx; i>=1; i--){
            if(isRobot[i].second==true){    //현재 자리에 로봇이 있고
                
                if(i==N){                    //마지막 로봇은 그냥 내림
                    isRobot[i].first = 0;
                    isRobot[i].second = false;
                }
                else{
                    if(isRobot[i+1].second==false && beltArr[i+1]>=1){  //다음 자리에 로봇 없고, 내구도 1 이상이면
                        isRobot[i+1] = isRobot[i];    //다음 칸으로 옮기고
                        beltArr[i+1] -= 1;
                        isRobot[i].first = 0;        //옮겼으니까 초기화
                        isRobot[i].second = false;
                    }
                }
                
            }
        }
    }
    
}
//1번 : 회전 : 내구도 & 로봇 위치 shift
void shiftNumber(){
    
    //내구도 이동
    int tmp = beltArr[2*N];
    for(int i = 2*N -1; i>=1; i--){
        beltArr[i+1] = beltArr[i];
    }
    beltArr[1] = tmp;
    
    
    //로봇 이동
    //내리는 위치의 로봇 처리
    isRobot[N].first = 0;
    isRobot[N].second = false;
    
    for(int i = N-1; i>=1; i--){
        isRobot[i+1] = isRobot[i];
    }
    isRobot[1].first=0;
    isRobot[1].second = false;
    
}

//3번 : beltArr[1]에 로봇없으면 로봇 하나 올림
bool putRobot(int order){
    
    if(beltArr[1]>=1 && isRobot[1].second==false) {    //처음칸의 내구도 1 이상이고 로봇 없으면
        beltArr[1]-=1;  //내구도 1 감소
        
        isRobot[1].first = order;
        isRobot[1].second = true;
        return true;
    }
    return false;
}

int solution(){
    
    int ord = 1;
    int step = 1;
    while(1){
        
        //한칸회전
        
        shiftNumber();
        if(cntZero()){break;}
        
        
        //먼저 올라간 로봇부터 전진
        shiftRobot();

        if(cntZero()){break;}
        
        //1번 비었으면 로봇 올림
        if(putRobot(ord)){        //로봇 올릴 수 있었으면 ord++
            ord++;
        }
        
        if(cntZero()){break;}
        step+=1;
    }
    
    return step;
}

int main(){
    
    
    cin>>N>>K;
    
    for(int i = 1; i<=N; i++){
        scanf("%d", &beltArr[i]);
        isRobot[i].first = 0;
        isRobot[i].second = false;
    }
    for(int i = N+1; i<=2*N; i++){
        scanf("%d", &beltArr[i]);
    }
    
    cout << solution();
    
    return 0;
}
