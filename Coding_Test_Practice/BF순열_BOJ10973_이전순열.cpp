#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main(){


    cin >> N;
    int num;
    for(int i = 0; i<N; i++){
        cin >> num;
        vec.push_back(num);
    }


    if(prev_permutation(vec.begin(), vec.end())){
        
        for(int i = 0; i<N; i++){
            cout << vec[i] << " ";
        }
    }
    else{
        cout << -1;
    }
        
        
   

    return 0;
}


//int main(){
//
//    greaterVec = {1,3,2};
//
//    while(next_permutation(greaterVec.begin(), greaterVec.end())){
//        for(int i = 0; i<3; i++){
//            cout << greaterVec[i] << " ";
//        }cout << "\n";
//    }
//
//    return 0;
//}
