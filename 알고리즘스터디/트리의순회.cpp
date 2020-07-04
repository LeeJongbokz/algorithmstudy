#include <iostream>

using namespace std;

const int MAX = 100000 + 10;

int inOrder[MAX];
int postOrder[MAX];
int idx[MAX];


void preOrder(int inBegin, int inEnd, int postBegin, int postEnd){
    
    // 기저 조건에 도달하면 return을 함
    if( (inBegin > inEnd) || (postBegin > postEnd)){
        return;
    }
    
    // 후위순회의 맨 마지막 값이 root임
    int root = postOrder[postEnd];
    
    cout << root << " ";
    
    // L은 중위순회의 root를 기준으로 왼쪽의 것임
    int L = idx[root]-inBegin;
    
    // 왼쪽 범위를 다시 전위 순회를 해줌
    preOrder(inBegin, inBegin+L-1, postBegin, postBegin+L-1);
    
    // 오른쪽 범위를 다시 전위 순회를 해줌
    preOrder(inBegin+L+1, inEnd, postBegin+L, postEnd-1);
    
    
    
       
}





int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // 중위순회의 값을 초기화함
    for(int i=0; i<n; i++){
        cin >> inOrder[i];
    }
    
    // 후위순회의 값을 초기화함
    for(int i=0; i<n; i++){
        cin >> postOrder[i];
    }
    
    // 중위순회의 인덱스를 저장함
    for(int i=0; i<n; i++){
        idx[inOrder[i]] = i; 
    }
    
    // 전위순회 시작
    preOrder(0, n-1, 0, n-1);
    
    
    
    
    
    
    
    
    
    
    
}
