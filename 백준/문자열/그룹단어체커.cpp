#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int notGroup = 0; 
    
    for(int i=1; i<=N; i++){
       
        string str;
        cin >> str;
        int a[30] = {0};
        
        int len = str.length();
        int isError = 0; 
        
        for(int j=0; j<len; j++){
            int c = str[j] - 97;
            
            if(a[c] == 0){
                a[c] += 1;
            }else{
                if(str[j-1] == str[j]){
                    continue;
                }else{
                    isError += 1;
                    break;
                }
            }
            
        }
        
        
        if(isError == 1){
            notGroup += 1;
        }else{
            continue;
        }
        
    }
    
    cout << N-notGroup;
    
}
