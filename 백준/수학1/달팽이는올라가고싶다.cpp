#include <iostream>

using namespace std;

int main(){
    
    int A, B, V;
    cin >> A >> B >> V;
    
    int distance = A-B;
    
    int day;
    
    if((V-A) % (A-B) == 0){
        day += ((V-A)/(A-B)) + 1;
    }else{
        day += ((V-A)/(A-B)) + 2;
    }
    
    cout << day;
    
    
}
