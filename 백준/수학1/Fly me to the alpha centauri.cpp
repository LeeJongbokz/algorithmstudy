#include <iostream>
#include <cmath> 

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    
    for(int i=1; i<=T; i++){
        long long x, y;
        cin >> x >> y;
        
        long long distance;
        long long cnt = 0;
        
        distance = y-x;
        
        if(distance == 1){
            cnt = 1;
        }else if(distance == 2){
            cnt = 2;
        }else if(distance == 3){
            cnt = 3;
        }else{
            
            long long t = sqrt(distance); 
            long long h = t*(t+1);
                
            if(distance == t*t){
                           cnt = (2*t)-1;
            }else if(t*t < distance && distance <= h){
                           cnt = 2*t;
            }else if(h < distance && distance <(t+1)*(t+1)){
                           cnt = (2*t)+1;
            }
                 
        }
   
        cout << cnt << '\n'; 
          
    }
    
}
