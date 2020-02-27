#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	int num = n;

	while (num != 1) {
		num /= 2;
		answer += 1;
	}


	int start = 1;
	int end = n;
	int mid;
	int range;

	while (start <= end) {

		if (start + 1 == end) {
			break;
		}

		range = (end - start) + 1;
		mid = start + (range / 2) - 1;

		if ( (start <= a) && (a <= mid) && ((mid + 1) <= b) && (b <= end)) {
			break;
		}
		else if ( (start <= b) && (b<= mid) && ((mid + 1) <= a) && (a <= end)) {
			break;
		}
		else if ((start <= a) && (a <= mid) && (start <= b) && (b <= mid)) {
			end = mid;
			answer -= 1;
		}
		else if ((mid + 1 <= a) && (a <= end) && ((mid + 1) <= b) && (b <= end)) {
			start = mid + 1;
			answer -= 1;
		}

	}


	return answer;
}
