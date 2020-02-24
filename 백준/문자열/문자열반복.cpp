#include <iostream>
#include <string> 

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        int R;
        cin >> R;
        
        string s;
        cin >> s;
        
        int len = s.length();
        
        for(int j=0; j<len; j++){
            for(int k=0; k<R; k++){
                cout << s[j];
            }
        }
        cout << '\n';
        
    }
    
    
    
}
