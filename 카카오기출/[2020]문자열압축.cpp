#include <string>
#include <vector>

using namespace std;

const int INF = 99999999;

int solution(string s) {
    int answer = 0;
    
    int len = s.size();

	int shortest = INF;

	string newString;

	for (int i = 1; i <= len; i++) {

		int newLen;

		if (i == len) {

			newLen = s.size();
			shortest = min(shortest, newLen);
			break;

		}

			newString.clear();

			int num = i;

			string start = s.substr(0, num);
			int cnt = 1;

			for (int j = num; j < len; ) {

				string next = s.substr(j, num);
				if (start == next) {
					cnt += 1;
					j += num;

					if (j >= len) {
						newString += to_string(cnt);
						newString += start;
						break;
					}

					continue;
				}
				else {

					if (cnt >= 2) {

						newString += to_string(cnt);
						newString += start;

					}
					else {
						newString += start;
					}

					start = next;
					cnt = 1;
					j += num;

					if (j >= len) {
						newString += start;
						break;
					}


				}

			}

			newLen = newString.size();

			shortest = min(shortest, newLen);


	}
    
    answer = shortest;
    
    return answer; 
    
}
    
