#include <iostream>
#include <vector> 

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    vector<int> v;
    
    int num = 2;
    
    while(1){
        if(N == 1){
            break;
        }
        
        if(N % num == 0){
            v.push_back(num);
            N /= num;
        }else{
            num += 1;
        }
    }
    
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    
    
    
}
