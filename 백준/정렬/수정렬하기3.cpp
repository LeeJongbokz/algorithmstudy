#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    int arr[10010]= {0};
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        arr[num] += 1;
    }
    
    for(int i=1; i<=10000; i++){
        int num = arr[i];
        
        for(int j=1; j<=num; j++){
            cout << i << '\n';
        }
    } 
    
    
       
    
}
