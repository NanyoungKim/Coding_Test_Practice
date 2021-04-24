//
//  SM_BOJ20058_마법사 상어와 파이어스톰.cpp
//  Coding_Test_Practice
//
//  Created by 김난영 on 2021/04/24.
//  Copyright © 2021 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;


int n, N, Q;
int A[65][65];            //얼음의 양
vector<int> vecL;
int visited[65][65];

//위 오 아 왼
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void leftIceChk() {



    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr<1 || nr>N || nc<1 || nc>N) continue;

                if (A[nr][nc] > 0) cnt++;

            }
            if (cnt < 3 && A[i][j]>0) {
                A[i][j] -= 1;
            }
        }
    }

}

int BFS(int r, int c){
    
    queue<pair<int,int>> que;
    que.push(make_pair(r,c));
    
    int sum = 0;
    
    while(!que.empty()){
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>N || nc<1 || nc>N || visited[nr][nc]==1) continue;
            
            sum++;
            visited[nr][nc] = 1;
            que.push(make_pair(nr,nc));
        }
    }
    
    return sum;
}




void rotateFunc(int s, int e) {    //돌리려는 격자의 시작점과 끝점

    for (; s < e; s--, e++) {//layer 점점 안쪽으로
        for (int i = s, j = e; i < e; i++, j--) {    //한칸씩 옮기기
            int tmp = A[s][j];
            A[s][j] = A[i][s];
            A[i][s] = A[i][e];
            A[i][e] = A[j][e];
            A[j][e] = tmp;
        }
    }


}

void printIce(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << A[i][j] << " ";
        }cout << "\n";
    }
    cout << "\n\n";
}

int main() {

    cin >> n >> Q;
    
    N = (int)pow(2,n);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < Q; i++) {
        int L; cin >> L;
        vecL.push_back(L);
    }

    for (int i = 0; i < vecL.size(); i++) {
        int len = (int)pow(2, vecL[i]);    //부분 격자 한변 길이

        int cnt = (N*N) / (len*len);    //회전시킬 박스 수

        int s = N, e =
        for (int k = 0; k < cnt; k++) {
            cout << s << " " << e << endl;
            rotateFunc(s, e);

            printIce();

            leftIceChk();        //얼음의 양 줄어듦
            printIce();
            
            e += len;
            if (e > N) {
                s -= len;
                e = 1;
            }
        }
    }
    //남아있는 얼음의 합
    int iceSum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(A[i][j]>0) iceSum += A[i][j];
        }
    }
    
    //남은 얼음 중 가장 큰 덩어리 안의 칸 개수
    int maxi = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(A[i][j] > 0){
                memset(visited, 0, sizeof(visited));
                
                int res = BFS(i, j);
                
                if(res>maxi) maxi = res;
                
            }
        }
    }

    cout << iceSum << "\n" << maxi;




    return 0;
}
