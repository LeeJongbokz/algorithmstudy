#include <iostream>

using namespace std;

int main(){
    
    int distance = 0;
    
    int N;
    cin >> N;
    
    
    if(N == 1){
        distance = 1;
    }else{
        
        int t = 2;
        int a = 2;
        int b = 7;
        
        while(1){
            if(a <= N && N<= b){
                distance = t;
                break;
            }else{
                a += 6*(t-1);
                b += 6*t;
                t += 1;
            }
        }
    }
    
    cout << distance;
    
    
    
}
