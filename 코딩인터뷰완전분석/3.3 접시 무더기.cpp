#include <iostream>

using namespace std;

const int MAX_STACK = 100;
const int MAX_SIZE = 100;

class Stack {

	int top;
	int data[MAX_SIZE] = { 0 };

public:

	Stack() {
		top = -1;
	}

	void push(int num) {
		if (top == MAX_SIZE) {
			cout << "Stack Overflow";
		}
		else {
			data[++top] = num;
		}
	}

	int pop() {
		if (top == 0) {
			cout << "Stack Underflow";
		}
		else {
			return data[top--];
		}
	}

	int size() {
		return top + 1;
	}


};

class SetOfStacks {


	Stack s[MAX_STACK];
	int curStk;

	public:

	SetOfStacks() {
		curStk = 0; 
	}

	void push(int num) {

		if (curStk == MAX_STACK && s[curStk].size() == MAX_SIZE) {
			cout << "Stack Overflow";
		}else if (s[curStk].size() >= MAX_SIZE) {
			curStk += 1;
			s[curStk].push(num);
		}
		else {
			s[curStk].push(num);
		}

	}
	
	void pop() {

		if (curStk == 0 && s[curStk].size() == 0) {
			cout << "Stack Underflow";
		}
		else if (curStk != 0 && s[curStk].size() == 0) {
			curStk--;
			s[curStk].pop();
		}
		else {
			s[curStk].pop();
		}
		
	}



};

int main() {


	SetOfStacks ss;

	ss.push(1);
	ss.push(2);

}
