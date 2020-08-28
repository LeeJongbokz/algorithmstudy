// 74분

#include <string>
#include <vector>
#include <stack>

using namespace std;


bool isRightbyStack(string input) {

	stack<char> s;

	bool isRight = true;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			s.push('(');
		}
		else if (input[i] == ')') {
			if (s.empty()) {
				isRight = false;
				break;
			}
			else {
				s.pop();
			}
		}
	}

	if (s.empty() && isRight == true) {
		return true;
	}
	else {
		return false; 
	}


}

void divide(string input, string& u, string& v) {


	int open = 0;
	int close = 0; 

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			open += 1;
		}
		else {
			close += 1;
		}

		if (open == close) {
			u = input.substr(0, i + 1);
			v = input.substr(i + 1);
			break;
		}
	}



}


string recursive(string input) {


	if (input == "") {
		return input;
	}
	else {

		bool isRight = isRightbyStack(input);

		if (isRight == true) {
			return input;
		}
		else {

			string u = "";
			string v = "";
			
			divide(input, u, v);

			string result; 

			if (isRightbyStack(u)) {
				result += u;
				result += recursive(v);
			}
			else {
				result += '(';
				result += recursive(v);
				result += ')';
				u.erase(u.begin());
				u.pop_back();

				for (int i = 0; i < u.size(); i++) {
					if (u[i] == '(') {
						u[i] = ')';
					}
					else {
						u[i] = '(';
					}
				}

				result += u;


			}

			return result; 

		}
	}



}

string solution(string p) {
    string answer = "";
    
    answer = recursive(p);
    return answer;
}
