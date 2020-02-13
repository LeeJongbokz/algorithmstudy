#include <vector>
#include <iostream>
using namespace std;

int N;
int cnt = 0;
int sum = 0; 
int arr[50010]={0};
bool check[1010] = {0};
vector<int> num;

void recursive(int index){
    
    if(index == 3){
        if(arr[sum] != 0){
            cnt += 1;
        }
        return;
    }
    
    for(int i=0; i<N; i++){
        if(check[i] == false){
            check[i] = true;
            sum += num[i];
            recursive(index+1);
            sum -= num[i];
            check[i] = false; 
        }
    }
        
}


int solution(vector<int> nums) {
    int answer = -1;
    
    N = nums.size();
    
    num = nums;
    
    for(int i=2; i<=50000; i++){
        arr[i] = i;
    }
    
    for(int i=2; i<=50000; i++){
        if(arr[i] == 0){
            continue;
        }
        
        for(int j=i+i; j<=50000; j+=i){
            if(arr[j] != 0){
                arr[j] = 0;
            }
        }
    }
    
    recursive(0);
    
    answer = cnt / 6; 

    return answer;
}
