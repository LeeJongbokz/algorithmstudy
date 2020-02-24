#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    
    for(int i=1; i<=T; i++){
        int H, W, N;
        cin >> H >> W >> N;
        
        int room;
        if(N % H != 0){
            room = (N%H)*100 + (N/H)+1;
        }else{
            room = (H*100)+(N/H);
        }
        
        cout << room << '\n';
    }
    
}
