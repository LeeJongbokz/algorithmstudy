#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

struct Meeting{
    int start;
    int end;
};

bool cmp(const Meeting &a, const Meeting &b){
    
    if(a.end == b.end){
        return a.start < b.start;
    }else{
        return a.end < b.end;
    }
    
}

int main(){
    
    
    int N;
    cin >> N;
    
    vector<Meeting> a(N);
    
    for(int i=0; i<N; i++){
        cin >> a[i].start;
        cin >> a[i].end;
    }
    
    sort(a.begin(), a.end(), cmp);
    
    int now = 0;
    int ans = 0;
    
    for(int i=0; i<a.size(); i++){
        if(now <= a[i].start){
            now = a[i].end;
            ans += 1;
        }
    }
    
    cout << ans;
    
    
    
    
    
    
}
