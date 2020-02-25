#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    long long a[1000010] = {0};
    
    a[1] = 1;
    a[2] = 2;
    
    for(int i=3; i<=N; i++){
        a[i] = a[i-1] + a[i-2];
        a[i] %= 15746;
    }
    
    
    cout << a[N];
    
    
}
