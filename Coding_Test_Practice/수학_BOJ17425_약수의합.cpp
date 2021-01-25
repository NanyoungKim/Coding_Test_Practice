#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

vector<long long> ansVec;
vector<int> numVec;

long long arrG[1000001]= {0};
long long arrF[1000001];



int main(){

    arrG[0] = 0; arrG[1] = 1;


    for(int i = 0; i<=1000001; i++){
        arrF[i] = 1;
    }

    for(int i = 2; i<=1000001; i++){

        for(int j = 1; j*i <= 1000001; j++){
            arrF[i*j] += i;
        }
    }

    for(int i = 1; i<=1000001; i++){
        arrG[i] = arrG[i-1] + arrF[i];
    }


    int tc;
    cin >> tc;
    for(int t = 1; t<=tc; t++){

        int N;
        cin >> N;

        cout << arrG[N] << "\n";
    }


    return 0;
}


