#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N,K;
    cin >> N >> K;
    
    vector<int> v;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int ans = 0; 
    
    for(int i=N-1; i>=0; i--){
            ans += (K/v[i]);
            K %= v[i];
    }
    
    cout << ans;
    
    
    
    
}
