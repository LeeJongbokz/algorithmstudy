#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAX_SIZE = 100;

class Stack {


	int top;
	int data[MAX_SIZE];
	vector<int> v;


public:

	Stack() {
		top = -1;
	}

	void push(int input) {
		if (top == MAX_SIZE) {
			cout << "Stack overflow";
		}
		else {

			if ((*this).isEmpty()) {
				push2(input);
			}
			else {
				v.clear();
				v.push_back(input);

				while (!(*this).isEmpty()) {
					int num = (*this).peek();
					(*this).pop();
					v.push_back(num);
				}

				sort(v.begin(), v.end(), greater<int>());

				for (int i = 0; i < v.size(); i++) {
					(*this).push2(v[i]);
				}
			}

		}
	}

	void push2(int input) {
		if (top == MAX_SIZE) {
			cout << "Stack overflow";
		}
		else {
			data[++top] = input;
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

	bool isEmpty() {
		return top == -1;
	}

	int peek() {
		if (top == -1) {
			cout << "Stack underflow";
		}
		else {
			return data[top];
		}
	}

};




int main() {

	Stack s1;
	s1.push(4);
	s1.push(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);

	cout << s1.peek();


}
