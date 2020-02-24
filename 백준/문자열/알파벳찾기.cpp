#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int len = s.length();
    
    int a[30] = {0};
    
    for(int i=0; i<26; i++){
        a[i] = -1;
    }
    
    for(int i=0; i<len; i++){
        int num = s[i] - 97;
        if(a[num] == -1){
            a[num] = i;
        }
    }
    
    for(int i=0; i<26; i++){
        cout << a[i] << " ";
    }
    
    
    
}
