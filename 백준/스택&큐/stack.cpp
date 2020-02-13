#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

class ArrayStack{

  private:
    int top;
    int data[MAX_SIZE];

  public:
    ArrayStack(){ top = -1;}
    ~ArrayStack(){}
    bool isEmpty(){ return top == -1;}
    bool isFull(){ return top == MAX_SIZE-1; }

    void push(int e){
      if(isFull()){
        cout << "Stack Overflow";
      }
       
       data[++top] = e; 
      
    }
    
    
    int pop(){
      if(isEmpty()){
        cout << "Stack Underflow";
      }
      return data[top--];
    }
    
    int peek(){
       if(isEmpty()){
         cout << "Stack Underflow";
       }
       
       return data[top];
    }
    
    void display(){
    
        for(int i=0; i<=top; i++){
          cout << data[i] << " ";
        }
        cout << '\n';
    }

}
