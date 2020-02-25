#include <iostream>

using namespace std; 

int main(){
    
    
    string str;
    cin >> str;
    
    int len = str.length();
    int a[30] = {0};
    
    for(int i=0; i<len; i++){
        int num = str[i] - 97;
        a[num] += 1;
    }
    
    for(int i=0; i<26; i++){
        cout << a[i] << " ";
    }
    
    
    
}
