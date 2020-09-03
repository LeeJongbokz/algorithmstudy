// 20분

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> stk;
    int len = board.size(); 
    
    for(int i=0; i<moves.size(); i++){
        
        int pos = moves[i];
        
        for(int j=0; j<len; j++){
            if(board[j][pos-1] == 0){
                continue;
            }else{
                int num = board[j][pos-1];
                
                if(stk.empty()){
                    stk.push(num);
                }else{
                    int topNum = stk.top();
                    if(num == topNum){
                        stk.pop();
                        answer += 2;
                    }else{
                        stk.push(num);
                    }
                }
                
                board[j][pos-1] = 0; 
                break;
            }
        }
    }
    
    
    
    
    
    
    return answer;
}
