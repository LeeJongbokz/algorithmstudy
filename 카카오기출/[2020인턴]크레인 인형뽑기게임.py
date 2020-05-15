배운 점:
(1) 보드에서 내가 0이 아닌 값을 발견하면,
    그 위치를 0으로 바꿔주고,
    break해야 함
    -> break해야만 더 이상 해당 열에 대해서 검사하지 않음
    + 왜 해당 열에서 검사하지 않아야 하는가?
    -> 해당 열에서는 이미 인형을 뽑았기 때문에, 더 검사해서는 안됨

def solution(board, moves):
    answer = 0
    
    // stack이라는 이름의 빈 배열을 선언함 
    stack = []
    
    // for문을 len(moves)만큼 순회함 
    for i in range(len(moves)):
        
        // pos는 내가 인형을 뽑아야 하는 열의 위치를 나타냄 
        pos = moves[i] - 1
        
        // for문을 len(board), 즉 행의 길이만큼 순회함 
        for j in range(len(board)):
            
            // board[j][pos] == 0이라면 행의 다음 위치를 탐색함 
            if board[j][pos] == 0 :
                continue
            // board[j][pos] != 0이라면,
            else:
                // 만약 stack 배열이 비어있으면,
                // stack 배열에 board[j][pos]를 그대로 넣어줌 
                if len(stack) == 0:
                    stack.append(board[j][pos])
                
                // 만약 stack 배열이 비어 있지 않으면,    
                else:
                    // 변수 top에 stack 배열의 맨 마지막 원소를 저장하고,  
                    top = stack[-1]
                    
                    // top과 새로 입력하는 board[j][pos]가 같은지를 검사함 
                    // 만약 같다면,
                    if board[j][pos] == top:
                        // 해당 원소를 pop하고
                        stack.pop()
                        // answer에 2를 더해줌 
                        answer += 2
                    // 만약 다르다면,
                    else:
                        //새로운 원소를 그냥 더해줌 
                        stack.append(board[j][pos])
                        
                // board[j][pos]는 이제 사용했으므로 0으로 바꿔줌 
                board[j][pos] = 0
                // break를 하는 이유는 이제 더 이상 추가적인 행에 대해 탐색하지 않아야 하기 때문임 
                break
    
    // 결과 값인 answer를 리턴함
    return answer 
