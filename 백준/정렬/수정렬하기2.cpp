#include <iostream>

using namespace std;

int N;
int arr[1000010];

void merge(int arr[], int left, int mid, int right){
    
    int i,j,k;
    
    i = left;
    j = mid + 1;
    k = left;
    
    int sorted[1000010];
    
    while(i<=mid && j<=right){
        if(arr[i] < arr[j]){
            sorted[k++] = arr[i++];
        }else{
            sorted[k++] = arr[j++];
        }
    }
    
    while(i<=mid){
        sorted[k++] = arr[i++];
    }
    
    
    while(j<=right){
        sorted[k++] = arr[j++];
    }
    
    
    for(int l=left; l<=right; l++){
        arr[l] = sorted[l];
    }   
    
}


void merge_sort(int arr[], int left, int right){
    
    if(left < right){
        int mid = (left+right) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    
    }
}

int main(){
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    merge_sort(arr, 0, N-1);
    
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }
    
    
    
    
    
}
