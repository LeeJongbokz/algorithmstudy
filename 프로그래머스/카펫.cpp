#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    
    vector<int> v1;
    vector<int> v2;
    vector<int> answer;
    
    int total = brown + red;
    
    for(int i=1; i<=total; i++){
        if( (total % i) == 0){
            v1.push_back(i);
        }
    }
    
    for(int i=0; i<v1.size(); i++){
        if( v1[i] >= (total/v1[i])){
            v2.push_back(v1[i]);
        }
    }
    
    for(int i=0; i<v2.size(); i++){
         int m = v2[i];
         int n = (total / v2[i]);
        
         if(2*m+2*n-4 == brown && (m*n-2*n-2*m+4) == red){
             answer.push_back(m);
             answer.push_back(n);
         }
    }

    return answer;
}
