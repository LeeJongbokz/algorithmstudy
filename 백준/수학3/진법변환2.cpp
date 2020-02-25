#include <iostream>
#include <vector> 

using namespace std;

int N, B;
vector<int> v;

void recursive(int num){
    
    if(num == 0){
        return;
    }else{
        recursive(num/B);
        v.push_back(num%B);
    }
    
}

int main(){
    
    cin >> N >> B;
    
    recursive(N);
    
    for(int i=0; i<v.size(); i++){
        if(v[i] >=10){
            cout << (char)(v[i]+55);
        }else{
            cout << v[i];
        }
    }
    
    
    
    
}
