#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

int N, M;
vector<int> v;
bool check[20];

void recursive(int index){
    
    if(index == M){
        
        for(int i=0; i<v.size()-1; i++){
            if(v[i] < v[i+1]){
                continue;
            }else{
                return;
            }
        }
        
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(check[i] == false){
            check[i] = true;
            v.push_back(i);
            recursive(index+1);
            v.pop_back();
            check[i] = false;
        }
    }
    
    
}


int main(){
    
    memset(check, 0, sizeof(check));
    
    cin >> N >> M;
    
    recursive(0);
    
    
    
    
}
