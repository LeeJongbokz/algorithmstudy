#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    vector<int> v;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            ans += v[j];
        }
    }
    
    cout << ans;
    
}
