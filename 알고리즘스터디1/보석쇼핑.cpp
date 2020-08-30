#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 999999; 

int len;
int shortest = INF;
vector<string>uniqueList;
vector<int> answer;
map<string, int> m; 
int uniqueLen; 

bool gemShopping(int num, int len, vector<string>& gems) {

    m.clear(); 

    for (int i = 0; i <= len - num; i++) {

        if (i == 0) {
            for (int j = 0; j < num; j++) {

                if (m.count(gems[i + j]) > 0) {
                    m[gems[i + j]] += 1;
                }
                else {
                    m.insert(pair<string, int>(gems[i + j], 1));
                }
            }

            if (m.size() == uniqueLen && shortest >= num) {
                shortest = num; 
                answer.clear();
                answer.push_back(i + 1);
                answer.push_back(i + 1 + num - 1);
                return true;
            }
        }
        else {

            string addString = gems[i + num - 1];
            string removeString = gems[i - 1];

            if (m.count(addString) > 0) {
                m[addString] += 1;
            }
            else {
                m.insert(pair<string, int>(addString, 1));
            }
 
            if (m[removeString] >= 2) {
                m[removeString] -= 1;
            }
            else {
                m.erase(removeString);
            }

            if (m.size() == uniqueLen && shortest >= num) {
                shortest = num;
                answer.clear();
                answer.push_back(i + 1);
                answer.push_back(i + 1 + num - 1);
                return true;
            }

        }

       

    }

    return false;

}


void binarySearch(int len, vector<string>&gems){
    
    int start = 1;
    int end = len;
    
    while(start <= end){
        
        int mid = (start+end)/2;
        
        bool result = gemShopping(mid, len, gems);
        
        if(result == true){
            end = mid-1;
        }else{
            start = mid+1;
        }
        
    }
}

vector<int> solution(vector<string> gems) {
    
    len = gems.size();
    
    uniqueList = gems;
    sort(uniqueList.begin(), uniqueList.end());
    uniqueList.erase(unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());
    
    uniqueLen = uniqueList.size(); 
    
    binarySearch(len, gems);
    
    
    return answer;
}
