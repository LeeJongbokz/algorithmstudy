#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std; 

bool cmp(string &a, string &b){
    
    if(a.length() < b.length()){
        return true;
    }else if(a.length() == b.length()){
        
        for(int i=0; i<a.length(); i++){
            if(a[i] == b[i]){
                continue;
            }else if(a[i] < b[i]){
                return true;
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
    
    return false;
    
}


int main(){
    
    int N;
    cin >> N;
    vector<string> v(N);
    
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        
        v[i] = str;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    v.erase(unique(v.begin(), v.end()), v.end());
    
    int vsize = v.size();
    
    for(int i=0; i<vsize; i++){
        cout << v[i] << '\n';
    }
    
    
    
    
}
