#include <string>
#include <vector>

using namespace std;

vector<int> temp;

void recursive(int n){
    
    if(n == 0){
        return;
    }
    
    recursive(n/2);
    temp.push_back(n%2);

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int map1[20][20]={0};
    int map2[20][20]={0};
    
    for(int i=0; i<n; i++){
        
        temp.clear();
        recursive(arr1[i]);
        int len = temp.size();
        int cnt = n - len;
        int t = 0;  
        
        for(int j=0; j<n; j++){
            if(cnt >= 1){
                map1[i][j] = 0;
                cnt -= 1;
            }else{
                map1[i][j] = temp[t];
                t += 1;
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        
        temp.clear();
        recursive(arr2[i]);
        int len = temp.size();
        int cnt = n - len;
        int t = 0;  
        
        for(int j=0; j<n; j++){
            if(cnt >= 1){
                map2[i][j] = 0;
                cnt -= 1;
            }else{
                map2[i][j] = temp[t];
                t += 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        
        string str;
        
        for(int j=0; j<n; j++){
            if(map1[i][j] ==1 || map2[i][j]==1){
                str += '#';
            }else{
                str += ' ';
            }
        }
        answer.push_back(str);
    }
    
    
    
    return answer;
}
