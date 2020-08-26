#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999;

int minlen = INF;

int solution(string s) {
    
int answer = 0;
    
   int len = s.size();


	for (int i = 1; i <= len; i++) {

		string result; 
		string beforeTemp;
		int cnt = 1;

		for (int j = 0; j < len; j += i) {
			string temp = s.substr(j, i);
			
			if (beforeTemp.empty()) {
				beforeTemp = temp;
			}
			else {
				if (temp == beforeTemp) {
					cnt += 1;
				}
				else {

					if (cnt == 1) {
						result += beforeTemp;
						beforeTemp = temp;
					}
					else {
						result += to_string(cnt);
						result += beforeTemp;
						cnt = 1;
						beforeTemp = temp;
					}

				}
			}

			if (j+i >= len) {
				if (cnt == 1) {
					result += temp;
				}
				else {
					result += to_string(cnt);
					result += temp;
				}
			}

		}

		int resultlen = result.size();
		
		minlen = min(minlen, resultlen);
		
	}

    answer = minlen; 
    
    return answer;
}
