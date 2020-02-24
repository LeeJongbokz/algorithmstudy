#include <iostream>

using namespace std;

int main(){
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int revenue;
    revenue = C - B;
    
    if(revenue <= 0){
        cout << -1;
    }else{
        cout << (A/revenue)+1;
    }
    
    
    
}
