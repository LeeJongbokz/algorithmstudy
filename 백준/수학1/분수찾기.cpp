#include <iostream>

using namespace std;

int main(){
    
    int start = 1;
    int end = 3;
    
    int t1 = 2;
    int t2 = 3;
    int stage = 2;
    int order = 0; 
    int child = 0;
    int parent = 0; 
    
    int X;
    cin >> X;
    
    if(X == 1){
        cout << 1 << '/' << 1 << '\n';
        return 0; 
        
    }else{
     
        while(1){
            if(start < X && X <= end){
                break;
            }else{
                start += t1;
                end += t2;
                stage += 1;
                t1 += 1;
                t2 += 1;
            }
        }
    }
    
    
    if(stage % 2 == 0){
        order = X - start;
        child = order;
        parent = (stage+1)-order;
    }else{
        order = X - start;
        child = (stage+1)-order;
        parent = order;
    }
    
    cout << child << '/' << parent << '\n';
    
  
    
}
