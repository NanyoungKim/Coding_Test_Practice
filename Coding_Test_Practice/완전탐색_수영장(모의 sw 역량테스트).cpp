#include <iostream>

using namespace std;


int price[4];
int dayofMonth[13] = {0,};
int minMonth[13] = {0,};
int answer;

int min(int a, int b){
    int ans = 0;
    if(a>=b){
        ans = b;
    }
    else{
        ans = a;
    }
    return ans;
}


void search(int month, int sum_price){
    
    
    if(month > 12){
        if(answer >= sum_price){
            answer = sum_price;

        }
         return;
    }
    
    
    
    if(minMonth[month] == 0){
        search(month+1, sum_price);
    }
    else{
        
        
        search(month+1, minMonth[month]+sum_price);         //먼저 1일+1달권 썼을때 최소 값 찾기
        search(month+3, price[2]+sum_price);                //재귀로 거꾸로 가면서 3개월권 쓰기
        
        
    }
    
    
    
    
    
    
    
}


int main(){
    
    
    int T;
    cin >> T;
    
    for(int k = 0; k<T; k++){
        
        for(int i = 0; i<4; i++){
            cin >> price[i];
        }
        for(int i = 1; i<13; i++){
            cin >> dayofMonth[i];
            
            if(dayofMonth[i] != 0){
                
                minMonth[i] = min((dayofMonth[i]*price[0]), price[1]);      //1일권 썼을때랑 1달권 썼을 때 비교해서
                cout << "minMonth[" << i << "]" <<minMonth[i] << " ";       //더 싼 금액 저장
                
            }
            cout << endl;
        }
        
        
        
        
        
        
        
        
        
        
        
        answer = price[3];
        search(1,0);
        
        cout << "#t " << answer << endl;
        
        
        
        
        
    }
    
    
    return 0;
}
