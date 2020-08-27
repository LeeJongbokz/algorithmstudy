#include <iostream>

using namespace std;


class Stack {

	int stackStart;
	int top;
	int maxPos;
	int data[300];

	public:
		Stack(int start, int max) {
			stackStart = start;
			top = start;
			maxPos = max;
		}

		void push(int num) {
			if (top == maxPos) {
				cout << "Stack Overflow";
			}
			else {
				data[++top] = num;
			}
		}

		int pop() {
			if (top == stackStart) {
				cout << "Stack Underflow";
			}
			else {
				return data[top--];
			}

		}

		int getTop() {
		  return top;
		}

};





int main() {


	Stack s1(-1, 99);
	Stack s2(99, 199);
	Stack s3(199, 299);

	cout << s1.getTop() << '\n';
	cout << s2.getTop() << '\n';
	cout << s3.getTop() << '\n';

	s1.push(100);
	cout << s1.getTop() << '\n';


}
