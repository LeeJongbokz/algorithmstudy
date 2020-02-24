#include <iostream>

using namespace std;

int main(){
    
    int a = 0;
    int b = 0;
    
    int N;
    cin >> N;
    
    int result = 0;
    int isExist = 0; 
    
    for(int i=0; i<=1666; i++){
        
        for(int j=0; j<=1000; j++){
            if(3*i + 5*j == N){
                isExist = 1;
                a = i;
                b = j;
            }
            if(3*i + 5*j > N){
                break;
            }
        }
        
        if(isExist == 1){
            break;
        }
        
    }
    
    if(isExist == 1){
        result = a+b;
    }else{
        result = -1;
    }
    
    cout << result; 
    
}
