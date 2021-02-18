#include <iostream>
#include <vector>

using namespace std;

int A[1001] = {0};
int dp[1001] = {0};
vector<int> ansVec;

int main(){
    
    int N;
    cin >> N;
    
    vector<int> vecArr[1001];
    
    
    for(int i = 1; i<=N; i++){ cin >> A[i];}
    
    for(int i = 1; i<=N; i++){
        
        dp[i] = 1;
        vecArr[i].push_back(A[i]);          //현재 숫자보다 더 작은 숫자 못 찾았을 때 자기 자신 push 해서 길이 1인 수열 만듦
        
        
        for(int j = 1; j<i; j++){
            if(A[j] < A[i]){                    //지금 숫자보다 더 작은 숫자로 끝난 수열을 찾는다.
                if(dp[j] + 1 > dp[i]){          //그 수열들 중 길이가 가장 긴 것을 찾는다.
                    vecArr[i].clear();          //현재 숫자보다 더 작은 숫자를 찾았으므로 처음에 넣었던 자기자신 없앰.
                    vecArr[i] = vecArr[j];      //이 전에 가장 긴 수열을 그대로 가져와서
                    vecArr[i].push_back(A[i]);  //현재 숫자를 push 해서 현재 가장 긴 수열을 만들어 벡터 배열에 넣는다.
                    dp[i] = dp[j] + 1;          //현재 숫자도 붙였으니 최대 수열의 길이도 1 증가
                    
                }
            }
        }
            if(ansVec.size() < vecArr[i].size()) { ansVec = vecArr[i];}
        
    }
    
        cout << ansVec.size() << "\n";
        for(int i = 0; i<ansVec.size(); i++){
            cout << ansVec[i] << " ";
        }cout << endl;

    
    
    
    return 0;

}
    
    
