//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//#include <utility>
//
//using namespace std;
//
//
//int map[8][8]={0};
//int visited[8][8]={0};
//int fromStart[8][8]={0};
//
////위,오,아,왼
//int dr[4]={-1,0,1,0};
//int dc[4]={0,1,0,-1};
//
//
//vector<pair<int,int>> vec;
//
//int ans;
//int N,K;
//bool flag;
//
//
//int findMax(){
//
//    int max = fromStart[0][0];
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//
//            if(max < fromStart[i][j]){
//                max = fromStart[i][j];
//            }
//        }
//    }
//    return max;
//}
//
//
//void itit(){
//   ans = 0;
//   flag = true;
//
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            fromStart[i][j] = 0;
//
//        }
//    }
//
//}
//
//void DFS(int r, int c, int cut, int dist, bool flag){
//
//    //시작점 map[r][c], cut만큼 무조건 깎아야함
//
//
//    for(int i=0; i<4; i++){
//
//       int nr=r+dr[i];
//       int nc=c+dc[i];
//
//       if(nr>=4 || nr<0 || nc>=4 || nc<0|| visited[nr][nc]==1) continue;   //범위 벗어나거나 이미 방문했으면 pass
//
//        if(map[nr][nc] < map[r][c]){        //해당 칸 안 깎는 경우
//            ans = max(ans, dist+1);
//            visited[nr][nc] = 1;
//            DFS(nr, nc, cut, dist+1, flag);
//            visited[nr][nc] = 0;
//        }
//
//        else if(flag){  //깎는 경우
//            ans = max(ans, dist+1);
//            map[nr][nc] -= cut;
//            visited[nr][nc] = 1;
//            flag = false;
//            DFS(nr, nc, cut, dist+1, flag);
//            flag = true;
//            visited[nr][nc] = 0;
//            map[nr][nc] += cut;
//
//        }
//
//
//    }
//    //map[r][c] += cut;
//}
//
//void print(){
//
//    cout << "#fromStart\n";
//    for(int i=0; i<N; i++){
//           for(int j=0; j<N; j++){
//               cout << fromStart[i][j] << " ";
//           }
//        cout << "\n";
//    }
//}
//int main(){
//
//    int T;
//    cin >> T;
//
//    int max=0;
//    for(int test_case = 1; test_case <= T; test_case++){
//
//        itit();
//
//        cin >> N >>K;
//        for(int i=0; i<N; i++){
//          for(int j=0; j<N; j++){
//              cin>>map[i][j];
//              if(max<map[i][j]) max = map[i][j];
//
//          }
//        }
//
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//
//                if(max == map[i][j]) vec.push_back(make_pair(i,j));
//            }
//        }
//
//
//        for(int i = 0; i<vec.size(); i++){
//            for(int j = 0; j<=K; j++){
//
//                int row = vec[i].first;
//                int col = vec[i].second;
//
//                visited[row][col] = 1;
//                DFS(row, col, j, 1, true);    //flag이 true 이면 안 깎아서 깎을 수 있는 상태
//                visited[row][col] = 0;
//
//            }
//        }
//
//
//
//       // ans = findMax();
//        cout << "#" << test_case << " " << ans << "\n";
//
//    }
//
//}


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int map[8][8]={0};
int visited[8][8]={0};
int fromStart[8][8]={0};

//위,오,아,왼
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};


vector<pair<int,int>> vec;

int ans, maxV;
int N,K;
bool flag;

void itit(){
    maxV = 0;
    ans = 1;
    flag = true;
    vec.clear();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ visited[i][j] = 0; map[i][j] = 0;}
    }
}

void DFS(int r, int c, int dist, bool isCut){
    
    ans = max(ans, dist);
    
    for(int i=0; i<4; i++){

          int nr=r+dr[i];
          int nc=c+dc[i];
        
          //범위 벗어나거나 이미 방문했으면 pass
          if(nr>=4 || nr<0 || nc>=4 || nc<0|| visited[nr][nc]==1) continue;

           if(map[nr][nc] < map[r][c]){        //이미 내리막길이면
               //ans = max(ans, dist+1);
               visited[nr][nc] = 1;
               DFS(nr, nc, dist+1, flag);
               visited[nr][nc] = 0;
           }
            
        if(!isCut && map[nr][nc] >= map[r][c]){
            
            for(int cut = 1; cut<=K; cut++){
                isCut = true;
                map[nr][nc] -= cut;
                
                if(map[nr][nc] < map[r][c]){
                    visited[nr][nc] = 1;
                    DFS(nr, nc, dist+1, flag);
                    visited[nr][nc] = 0;
                }
                map[nr][nc] += cut;
                isCut = false;
            }
        }
        
        
    }
    
   
    
}






int main(){
    
    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){

        itit();

        cin >> N >>K;
        for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
              cin>>map[i][j];
              if(maxV<map[i][j]) {maxV = map[i][j];}
          }
        }
        //cout << "max: " << maxV <<"\n";

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(maxV == map[i][j]) vec.push_back(make_pair(i,j));
            }
        }

        
        //cout << vec.size() << "\n";
        
        for(int i = 0; i<vec.size(); i++){
            
            int row = vec[i].first;
            int col = vec[i].second;

            visited[row][col] = 1;
            DFS(row, col, 1, false);    //flag이 true 이면 안 깎아서 깎을 수 있는 상태
            visited[row][col] = 0;


        }


       
        cout << "#" << test_case << " " << ans << "\n";

    }
    
    
    
    
    return 0;
}
