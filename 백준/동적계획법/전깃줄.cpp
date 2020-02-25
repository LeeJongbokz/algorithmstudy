#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    
       int dp[510]= {0};
    
       int N;
       cin >> N;
    
       vector<pair<int,int>> v;
    
       for(int i=0; i<N; i++){
           int x,y;
           cin >> x >> y;
           
           v.push_back(make_pair(x,y));

       }
    
    
       sort(v.begin(), v.end());
    
    
       for(int i=0; i<N; i++){
             dp[i] = 1;
           
             for(int j=0; j<i; j++){
                 if(v[j].second < v[i].second && dp[i] == dp[j]){
                     dp[i] = dp[j] + 1;
                 }
             }
       }
       
      
       int longest = dp[0];
    
       for(int i=1; i<N; i++){
             if(longest < dp[i]){
                 longest = dp[i];
             }
       }
    
       cout << N-longest; 
    
    
    
    
    
    
    
    
    
    
}
