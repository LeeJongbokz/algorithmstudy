#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int order = 0;
int N;

int main(){
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        int weight, height;
        cin >> weight >> height;
        v.push_back(make_pair(weight, height));
    }
    
    for(int i=1; i<=N; i++){
        int weight1, height1;
        int order = 1;
        
        weight1 = v[i-1].first;
        height1 = v[i-1].second;
        
        for(int j=1; j<=N; j++){
            if(i!=j){
                if(weight1 < v[j-1].first && height1 < v[j-1].second){
                    order += 1;
                }
            }
        }
        
        cout << order << " ";
        
    }
    
    
    
    
}

