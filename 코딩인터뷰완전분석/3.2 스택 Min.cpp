#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

class Stack {

	int top;
	int data[MAX_SIZE];
	vector<int>v;

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
				saveVector(num);
			}
		}

		int pop() {
			if (top == -1) {
				cout << "Stack underflow";
			}
			else {
				removeVector(data[top--]);
				return data[top--];
			}
		}

		int min() {
			if (top == -1) {
				cout << "Stack underflow";
			}
			else {
				return v.back();
			}
		}

		void saveVector(int num) {
			v.push_back(num);
			sort(v.begin(), v.end(), greater<int>());
		}

		void removeVector(int num) {

			int pos = 0; 

			for (int i = 0; i < v.size(); i++) {
				if (v[i] == num) {
					pos = i;
				}
			}

			v.erase(v.begin() + pos);
		}




};

int main() {


	Stack s;
	s.push(1);
	s.push(-3);
	s.push(10);
	s.push(12);
	s.pop();

	cout << s.min();


}
