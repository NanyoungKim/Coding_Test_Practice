#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main(){


    cin >> N;
    for(int i = 0; i<N; i++){
        vec.push_back(i+1);
    }

    do{
        for(int i = 0; i<N; i++){
            cout << vec[i] << " ";
        }cout << "\n";
        
    } while(next_permutation(vec.begin(), vec.end()));


    return 0;
}


