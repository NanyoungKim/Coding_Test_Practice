#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;

int main(){
    
    
    int cnt, ans;
    cin >> cnt;
    
    for(int i = 0; i<cnt; i++){
        
        int num;
        cin >> num;
        vec.push_back(num);
        
    }
    sort(vec.begin(), vec.end());
    ans = vec[0] * vec[cnt-1];

    cout << ans << "\n";
    
    return 0;
}
