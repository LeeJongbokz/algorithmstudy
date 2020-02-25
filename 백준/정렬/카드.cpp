#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;
int N;

void printCard(){
    
      sort(v.begin(), v.end());
    
      long long card; 
    
      int cnt = 1;
      int maxCnt = 0;
    
      for(int i=1; i<N; i++){
           
          if(v[i-1] == v[i]){
              cnt++;
          }else if(v[i-1] != v[i] && maxCnt < cnt){
              maxCnt = cnt;
              card = v[i-1];
              cnt = 1;
          }else if(v[i-1] != v[i] && maxCnt >= cnt){
              cnt = 1; 
          }
          
      }
    
      if(maxCnt < cnt){
          card = v[N-1];
      }
    
      cout << card << '\n';
    
}



int main(){
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        
        long long num;
        cin >> num;
        
        v.push_back(num);
    }
    
    printCard();
    
    return 0; 
    
}









