#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    
    int d1 = x;
    int d2 = y;
    int d3 = w-x;
    int d4 = h-y;
    
    int minNum = min(d1, d2);
    minNum = min(minNum, d3);
    minNum = min(minNum, d4);
    
    cout << minNum;
    
    
    
    
}
