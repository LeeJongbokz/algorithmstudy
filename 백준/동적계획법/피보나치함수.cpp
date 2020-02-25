#include <iostream>

using namespace std;


int main(){
    
    long long cnt0[100]={0};
    long long cnt1[100]={0};
    
    
    cnt0[0] = 1;
    cnt1[0] = 0;
    
    cnt0[1] = 0;
    cnt1[1] = 1;
    
    for(int i=2; i<=40; i++){
        cnt0[i] = cnt0[i-1]+cnt0[i-2];
        cnt1[i] = cnt1[i-1]+cnt1[i-2];
    }
    
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        
        int N;
        cin >> N;
        
        cout << cnt0[N] << " " << cnt1[N] << '\n';
    }
    

     
}
