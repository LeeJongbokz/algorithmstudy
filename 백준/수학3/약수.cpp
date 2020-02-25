#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){
    
    vector<int> v;
    
    int num;
    cin >> num;
    
    for(int i=1; i<=num; i++){
          int yaksu;
          cin >> yaksu;
        
          v.push_back(yaksu);
    }
    
    
    sort(v.begin(), v.end());
    
    int vSize = v.size();
    
    int result = v[0]*v[vSize-1];
    
    cout << result;
    
    
 
    
    
    
}
