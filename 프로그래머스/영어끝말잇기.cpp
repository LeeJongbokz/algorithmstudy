#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> used;
    int order = 0;
    int len = words.size();
    
    for(int i=0; i<len; i++){
        string temp = words[i];
        int usedlen = used.size();
        
        for(int j=0; j<usedlen; j++){
            if(used[j] == temp){
                order = i+1;
                break;
            }
        }
        
        if(i >= 1){
            int wordlen = words[i-1].length();
            if(words[i-1][wordlen-1] != words[i][0]){
                order = i+1;
            }
        }
        
          if(order == 0){
             used.push_back(temp);
          }else{
           break;
          }
    }
    
  
    
    int a = 0;
    int b = 0; 
    
    if(order != 0){
        if(order % n == 0){
            a = n;
            b = order / n;
        }else{
            a = order % n;
            b = (order / n) + 1;
        }
    }
    
    answer.push_back(a);
    answer.push_back(b);
    
    

    return answer;
}
