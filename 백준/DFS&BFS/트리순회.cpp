#include <iostream>

using namespace std;

struct Node{
    char left;
    char right;
};

struct Node arr[100];


void preOrder(char root){
    
    if(root=='.'){
        return;
    }else{
        cout << root;
        preOrder(arr[root].left);
        preOrder(arr[root].right);
    }
    
}


void inOrder(char root){
    
    if(root=='.'){
        return;
    }else{
        inOrder(arr[root].left);
        cout << root;
        inOrder(arr[root].right);
    }
    
}


void postOrder(char root){
    
    if(root=='.'){
        return;
    }else{
        postOrder(arr[root].left);
        postOrder(arr[root].right);
        cout << root;
    }
    
}




int main(){
    
    
    int N;
    cin >> N;
    
    
    for(int i=1; i<=N; i++){
        char a, b, c;
        cin >> a >> b >> c;
        
        arr[a].left = b;
        arr[a].right = c;
        
    }
    
    
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');    
    
}












