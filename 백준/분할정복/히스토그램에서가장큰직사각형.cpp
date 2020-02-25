#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> h;

long long solve(long long left, long long right){
    
    if(left == right){
        return h[left];
    }
    
    long long mid = (left+right)/2;
    
    long long ret = max(solve(left, mid), solve(mid+1, right));
    
    long long lo = mid, hi = mid + 1;
    long long height = min(h[lo], h[hi]);
    ret = max(ret, height*2);
    
    while(left < lo || hi < right){
        
        if(hi < right && (left == lo || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height, h[hi]);
        }else{
            lo--;
            height = min(height, h[lo]);
        }
        
        ret = max(ret, height*(hi-lo+1));
    }
    
    return ret; 
   
}




int main(){
    
    while(1){
        
        cin >> n;
        if(n == 0){
            break;
        }
        
        h.clear();
        
        for(int i=1; i<=n; i++){
            long long num;
            cin >> num;
            h.push_back(num);
        }
        
        cout << solve(0, n-1) << '\n';
        
        
    }
    
    
    
}




