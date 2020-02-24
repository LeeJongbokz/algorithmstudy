#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        
        if(r2 - r1 > 0){
            swap(r1, r2);
        }
        
        if(d == 0){
            
            if(r1 == r2){
                cout << -1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if((r1-r2) == d || (r1+r2) == d){
            cout << 1 << '\n';
        }else if((r1-r2) < d && d < (r1+r2)){
            cout << 2 << '\n';
        }else{
            cout << 0 << '\n';
        }
        
    }
    
    
}
