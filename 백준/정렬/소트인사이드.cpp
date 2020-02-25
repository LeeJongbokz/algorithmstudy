#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    
    vector<int> v;
    
    string str;
    cin >> str;
    
    int len = str.length();
    
    for(int i= 0; i< len; i++){
        int num = str[i] - '0';
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int vlen = v.size();
    
    for(int i=0; i<vlen; i++){
        cout << v[i];
    }
    
    
}
