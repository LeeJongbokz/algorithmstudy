#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int sum = 0; 
    double mean = 0;
    
    int middle = 0;
    
    int mostFrequent = 0;
    int a[8010] = {0};
    
    int range = 0; 
    
    vector<int> v;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<N; i++){
        sum += v[i];
    }
    
    mean = (double)sum / (double)N;
    middle = v[N/2];
    range = v[N-1]-v[0];
    
    
    for(int i=0; i<N; i++){
        v[i] += 4000;
    }
    
    for(int i=0; i<N; i++){
         a[v[i]] += 1;
    }
    
    int maxNum = -1;
    int maxIndex = -1;
    
    for(int i=0; i<=8000; i++){
        if(maxNum < a[i]){
            maxNum = a[i];
            maxIndex = i;
        }
    }
    
    int isCount = 0; 
    
    for(int i=0; i<=8000; i++){
        if(maxNum == a[i]){
            isCount += 1;
        }
        
        if(isCount == 2){
            mostFrequent = i;
            break;
        }
    }
    
    if(isCount == 1){
        mostFrequent = maxIndex;
    }
    
    mostFrequent -= 4000;
    
    cout << round(mean) << '\n';
    cout << middle << '\n';
    cout << mostFrequent << '\n';
    cout << range;
     
    
}
