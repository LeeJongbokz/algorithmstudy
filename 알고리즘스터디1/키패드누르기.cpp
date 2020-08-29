// 46분

#include <string>
#include <vector>

using namespace std;


int getLeftDistance(int num, int leftNow, string hand) {

	int leftDistance = 0;

	if (num == 2) {
		if (leftNow == 1) {
			leftDistance = 1;
		}
		else if (leftNow == 4) {
			leftDistance = 2;
		}
		else if (leftNow == 7) {
			leftDistance = 3;
		}
		else if (leftNow == -1) {
			leftDistance = 4;
		}
		else if (leftNow == 2) {
			leftDistance = 0; 
		}
		else if (leftNow == 5) {
			leftDistance = 1;
		}
		else if (leftNow == 8) {
			leftDistance = 2;
		}
		else if (leftNow == 0) {
			leftDistance = 3;
		}

	}
	else if (num == 5) {

		if (leftNow == 1) {
			leftDistance = 2;
		}
		else if (leftNow == 4) {
			leftDistance = 1;
		}
		else if (leftNow == 7) {
			leftDistance = 2;
		}
		else if (leftNow == -1) {
			leftDistance = 3;
		}
		else if (leftNow == 2) {
			leftDistance = 1;
		}
		else if (leftNow == 5) {
			leftDistance = 0;
		}
		else if (leftNow == 8) {
			leftDistance = 1;
		}
		else if (leftNow == 0) {
			leftDistance = 2;
		}

	}
	else if (num == 8) {

		if (leftNow == 1) {
			leftDistance = 3;
		}
		else if (leftNow == 4) {
			leftDistance = 2;
		}
		else if (leftNow == 7) {
			leftDistance = 1;
		}
		else if (leftNow == -1) {
			leftDistance = 2;
		}
		else if (leftNow == 2) {
			leftDistance = 2;
		}
		else if (leftNow == 5) {
			leftDistance = 1;
		}
		else if (leftNow == 8) {
			leftDistance = 0;
		}
		else if (leftNow == 0) {
			leftDistance = 1;
		}
	}
	else if (num == 0) {

		if (leftNow == 1) {
			leftDistance = 4;
		}
		else if (leftNow == 4) {
			leftDistance = 3;
		}
		else if (leftNow == 7) {
			leftDistance = 2;
		}
		else if (leftNow == -1) {
			leftDistance = 1;
		}
		else if (leftNow == 2) {
			leftDistance = 3;
		}
		else if (leftNow == 5) {
			leftDistance = 2;
		}
		else if (leftNow == 8) {
			leftDistance = 1;
		}
		else if (leftNow == 0) {
			leftDistance = 0;
		}
	}

	return leftDistance;

}


int getRightDistance(int num, int rightNow, string hand) {

	int rightDistance = 0;

	if (num == 2) {
		if (rightNow == 3) {
			rightDistance = 1;
		}
		else if (rightNow == 6) {
			rightDistance = 2;
		}
		else if (rightNow == 9) {
			rightDistance = 3;
		}
		else if (rightNow == -1) {
			rightDistance = 4;
		}
		else if (rightNow == 2) {
			rightDistance = 0;
		}
		else if (rightNow == 5) {
			rightDistance = 1;
		}
		else if (rightNow == 8) {
			rightDistance = 2;
		}
		else if (rightNow == 0) {
			rightDistance = 3;
		}

	}
	else if (num == 5) {

		if (rightNow == 3) {
			rightDistance = 2;
		}
		else if (rightNow == 6) {
			rightDistance = 1;
		}
		else if (rightNow == 9) {
			rightDistance = 2;
		}
		else if (rightNow == -1) {
			rightDistance = 3;
		}
		else if (rightNow == 2) {
			rightDistance = 1;
		}
		else if (rightNow == 5) {
			rightDistance = 0;
		}
		else if (rightNow == 8) {
			rightDistance = 1;
		}
		else if (rightNow == 0) {
			rightDistance = 2;
		}

	}
	else if (num == 8) {

		if (rightNow == 3) {
			rightDistance = 3;
		}
		else if (rightNow == 6) {
			rightDistance = 2;
		}
		else if (rightNow == 9) {
			rightDistance = 1;
		}
		else if (rightNow == -1) {
			rightDistance = 2;
		}
		else if (rightNow == 2) {
			rightDistance = 2;
		}
		else if (rightNow == 5) {
			rightDistance = 1;
		}
		else if (rightNow == 8) {
			rightDistance = 0;
		}
		else if (rightNow == 0) {
			rightDistance = 1;
		}
	}
	else if (num == 0) {

		if (rightNow == 3) {
			rightDistance = 4;
		}
		else if (rightNow == 6) {
			rightDistance = 3;
		}
		else if (rightNow == 9) {
			rightDistance = 2;
		}
		else if (rightNow == -1) {
			rightDistance = 1;
		}
		else if (rightNow == 2) {
			rightDistance = 3;
		}
		else if (rightNow == 5) {
			rightDistance = 2;
		}
		else if (rightNow == 8) {
			rightDistance = 1;
		}
		else if (rightNow == 0) {
			rightDistance = 0;
		}
	}

	return rightDistance;

}




string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int leftNow = -1;
	int rightNow = -1;

	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];

		if (num == 1 || num == 4 || num == 7) {
			leftNow = num;
			answer += 'L';
		}
		else if (num == 3 || num == 6 || num == 9) {
			rightNow = num;
			answer += 'R';
		}
		else {
			int leftDistance = getLeftDistance(num, leftNow, hand);
			int rightDistance = getRightDistance(num, rightNow, hand);

			if (leftDistance < rightDistance) {
				leftNow = num;
				answer += 'L';
			}
			else if (leftDistance > rightDistance) {
				rightNow = num;
				answer += 'R';
			}
			else {
				if (hand == "left") {
					leftNow = num;
					answer += 'L';
				}
				else {
					rightNow = num;
					answer += 'R';
				}
			}
		}
	}
    
    
    
    
    
    return answer;
}
