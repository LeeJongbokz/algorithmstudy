
// 이 문제는 백트레킹 유형이며, 
// 따라서 적절한 재귀 함수를 작성하여 문제를 해결해야 함 

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 1000000000;

int N;
vector<int> v;
vector<char> symbol;
bool check[20];
int maxNum = -INF;
int minNum = INF;
int symbolLen; 


void calculate(int result, int index) {

	// index가 N이 되면, 벡터 v에 속한 모든 값을 연산했다는 것을 의미함
	// 왜냐하면 벡터 v의 길이는 N이고, 따라서 v[0], v[1], v[2], ... v[N-1]에 값이 존재하기 때문임
	// 이 때, result값이 maxNum이거나 minNum인지 확인하여 값을 업데이트함
	if (index == N) {
		if (result > maxNum) {
			maxNum = result;
		}
		if (result < minNum) {
			minNum = result;
		}
		return; 

	}

        // symbolLen, 즉 전체 기호의 개수만큼 
	// for문을 순회함 
	for (int i = 0; i < symbolLen; i++) {

		int remain;

		// bool형 배열 check[i]로 중복을 검사함
		// 특정 기호는 중복되어서 사용되어서는 안되기 때문임 
		// 한 번 사용한 기호는 check[i] = true로 처리함 
		if (check[i] == false) {
			
			// i번째 기호가 '+', '-', '*', '/'에 따라서
			// result에 연산을 해줌 
			// 단, 연산하는 값은 v[index]임
			if (symbol[i] == '+') {
				result += v[index];
			}
			else if (symbol[i] == '-') {
				result -= v[index];
			}
			else if (symbol[i] == '*') {
				result *= v[index];
			}
			// 단, '/'연산에 대해서는 remain, 즉 나머지 값을 저장할 필요가 있음
			// 왜냐하면 이후에 백트레킹 연산에서 나머지 값을 다시 더해줘야 하기 때문임 
			else if (symbol[i] == '/') {
				result /= v[index];
				remain = result % v[index];
			}
                        
			// 사용한 연산자에 대해서 true를 처리함
			check[i] = true;
			
			// 재귀함수에 진입함
			// 단, 이 때 index는 1 증가함
			calculate(result, index + 1);
			
			// 재귀함수로부터 리턴을 해서 백트레킹을 할 때는,
			// 기존에 사용했던 기호를 무효로 처리해야 함
			// 따라서 여기서는 check[i]를 다시 false로 바꿔줌 
			check[i] = false;

			// 마찬가지로 기존에 연산했던 값을 무효로 처리해야 함
			// 따라서 여기서는 '+'일 때는 -, '-'일 때는 +
			// '*'일 때는 '/', '/'일 때는 '*'을 해줘야 함
			
			// 단, 이 때 주의할점은 '/'연산 같은 경우는 
			// '*'을 해줄 때, 나머지 값을 더해줘야 한다는 것임
			// 이 부분이 이 문제에서 제일 중요한 부분임
			// 예를 들어, 이전에 10%3 = 3 ... 1 을 연산했더라면
			// 여기서는 그 연산을 무효화하기 위해서
			// 3*3+1 = 10을 해줘야하는 것임 
			if (symbol[i] == '+') {
				result -= v[index];
			}
			else if (symbol[i] == '-') {
				result += v[index];
			}
			else if (symbol[i] == '*') {
				result /= v[index];
			}
			else if (symbol[i] == '/') {
				result = result*v[index]+remain;
			}




		}



	}


}


int main() {

	// bool형 check 배열을 false로 초기화함
	// 이 배열은 재귀 함수에서 기호의 중복 사용을 막기 위해서 사용함
	memset(check, false, sizeof(check));

	cin >> N;

	// 벡터 v에 N개의 수를 저장함
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	// 덧셈, 뺄셈, 곱셈, 나눗셈의 개수를 입력함
	int plus, minus, multiply, divide = 0;
	cin >> plus >> minus >> multiply >> divide;
	
	// 벡터 symbol에 4가지 기호들을 각각의 개수만큼 저장함
	for (int i = 0; i < plus; i++) {
		symbol.push_back('+');
	}

	for (int i = 0; i < minus; i++) {
		symbol.push_back('-');
	}

	for (int i = 0; i < multiply; i++) {
		symbol.push_back('*');
	}

	for (int i = 0; i < divide; i++) {
		symbol.push_back('/');
	}

	// 변수 start에 벡터 v의 첫번째 값을 저장함 
	int start = v[0];
	// 변수 symbolLen에 전체 기호들의 갯수를 저장함
	symbolLen = symbol.size(); 

	// 재귀 함수 calculate를 시작함
	// 이 때, 첫번째 parameter인 result는 연산의 결과를 기록하고, 
	// 두번째 parameter인 index는 벡터 v 상에서의 위치를 나타냄 
	calculate(start, 1);

	// 재귀 함수를 통해서 얻게 된 결과 값인
	// maxNum 과 minNum을 각각 출력함 
	cout << maxNum << '\n';
	cout << minNum;


}
