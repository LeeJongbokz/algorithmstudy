#include <iostream>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int len = s.length();
    int a[30] = {0};
    
    for(int i=0; i<len; i++){
        if(65<=s[i] && s[i] <= 90){
            int num = s[i] - 65;
            a[num] += 1;
        }else if(97<=s[i] && s[i] <= 122){
            int num = s[i] - 97;
            a[num] += 1;
        }
    }
    
    int maxNum = a[0];
    int maxIndex = 0;
    
    for(int i=1; i<26; i++){
        if(maxNum < a[i]){
            maxNum = a[i];
            maxIndex = i;
        }
    }
    
    int cnt = 0;
    
    for(int i=0; i<26; i++){
        if(a[i] == maxNum){
            cnt += 1;
        }
    }
    
    
    if(cnt >= 2){
        cout << "?" << '\n';
    }else{
        cout << char(maxIndex+65) << '\n';
    }
        
    
    
}
