#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main(){
    
    string str;
    int B;
    cin >> str >> B;
    
    int len = str.length();
    
    int sum = 0;
    int t = 0; 
    
    for(int i=len-1; i>=0; i--){
        if(65<=str[i] && str[i] <= 90){
            int num = str[i] - 55;
            sum += (num)*pow(B, t);
            t += 1;
        }else{
            int num = str[i] - 48;
            sum += (num)*pow(B, t);
            t += 1;
        }
    }
    
    cout << sum;
    
   
    
    
    
    
}
