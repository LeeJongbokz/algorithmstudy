#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {

	int top;
	int data[MAX_SIZE];

	public:

		Stack() {
			top = -1;
		}

		void push(int num) {
			if (top == MAX_SIZE) {
				cout << "Stack overflow";
			}
			else {
				data[++top] = num;
			}
		}

		int pop() {
			if (top == -1) {
				cout << "Stack underflow";
			}
			else {
				return data[top--];
			}
		}

		int getTop() {
			if (top == -1) {
				cout << "Stack underflow";
			}
			else {
				return data[top];
			}
		}

		bool empty() {
			return top == -1;
		}


};


class MyQueue {
	Stack s1;
	Stack s2;


	public:

	void push(int num) {
		s1.push(num);
	}

	int pop() {

		while (!s1.empty()) {
			int num = s1.getTop();
			s1.pop();
			s2.push(num);
		}

		int num = s2.getTop();
		s2.pop();

		while (!s2.empty()) {
			int num = s2.getTop();
			s2.pop();
			s1.push(num);
		}

		return num;

	}



};



int main() {

	MyQueue q;

	q.push(100);
	q.push(1);
	q.push(2);
	q.push(3);
	int num = q.pop();
	cout << num;


}
