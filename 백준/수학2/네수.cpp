#include <iostream>
#include <cmath> 
#include <string> 

using namespace std; 

int main(){
    
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    string str1, str2, str3, str4;
    string str5, str6; 
    
    str1 = to_string(A);
    str2 = to_string(B);
    str3 = to_string(C);
    str4 = to_string(D);
    
    str5 = str1 + str2;
    str6 = str3 + str4;
    
    long long sum = 0;
    
    int len1 = str5.length();
    int len2 = str6.length();
    
    int t1 = 0;
    int t2 = 0;
    
    for(int i=len1-1; i>=0; i--){
        int num = str5[i] - 48;
        sum += num*pow(10, t1);
        t1 += 1;
    }
    
    for(int i=len2-1; i>=0; i--){
        int num = str6[i] - 48;
        sum += num*pow(10, t2);
        t2 += 1;
    }
    
    cout << sum;
    
    
       
    
    
    
}
