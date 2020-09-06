// 15분

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown+yellow;
    int tempW = total;
    int width;
    int height; 
    
    while(1){
        if(total % tempW == 0){
            width = tempW;
            height = total / tempW;
        }
        
        int tempBrown = width*2+height*2-4;
        int tempYellow = total-tempBrown;
        
        if(tempBrown == brown && tempYellow && yellow){
            break;
        }else{
            tempW--;
        } 
    }
    
    answer.push_back(width);  
    answer.push_back(height);
    
    return answer;
}
