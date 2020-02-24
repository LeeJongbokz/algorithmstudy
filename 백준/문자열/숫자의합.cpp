#include <iostream>

using namespace std;

int main(){
    
    int sum = 0;
    int N;
    cin >> N;
    
    string str;
    cin >> str;
    
    int len = str.length();
    
    for(int i=0; i<len; i++){
        int num = str[i] - '0';
        sum += num;
    }
    
    cout << sum;
    
    
}
