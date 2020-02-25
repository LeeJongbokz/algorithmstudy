#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    vector<string> v;
    int len = str.length();
    
    for(int i=0; i<len; i++){
        string temp;
        for(int j=i; j<len; j++){
            temp += str[j];
        }
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int vlen = v.size();
    
    for(int i=0; i<vlen; i++){
        cout << v[i] << '\n';
    }
    
    
 
    
    
}




