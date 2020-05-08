
// 이 문제의 경우는 구현 문제임
// 구현 문제 같은 경우는, 우선 문제의 조건을 세세하게 이해하는 것이 중요함
// 또한, 문제의 조건을 이해한 것을 예제 테스트케이스에 대입하면서 머릿속에 그림을 그릴 수 있어야 함

// 구현을 명확하기 위해서는 몇 가지 조각으로 구분해서 사고하는 것이 좋음
// 보통 하나의 문제에 3~4개 혹은 그 이상의 조각을 구현해야 함
// 따라서 단순히 생각하면 여러 개의 조각을 구현하는 문제로 볼 수 있음
// 따라서 한 조각씩 정확히 구현을 해 나간다는 관점을 취하면 도움이 됨  

// 이 문제 같은 경우는 다른 사람의 코드도 살펴볼 필요가 있음
// 더 효율적으로 구현할 수 있는 방법이 있을 듯함 

// 이 문제의 핵심 포인트는 '*'와 '#'에 대해서 얼마나 효율적이고 정확하게 구현할 것인가임 

#include <string>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    
    int answer = 0; 
    
    // dartResult는 string이고,
    // 따라서 len = dartResult.length()로
    // string dartResult의 길이를 구해줌 
    int len = dartResult.length();
    
    int temp = 0; 
    
    // dartResult[i] == 1, dartResult[i+1] == '0'이면 
    // dartResult[i]의 값을 ':'로 바꿔줌
    // ':'로 바꿔주는 이유는 ':'의 아스키코드 값이 58이고,
    // 따라서 나중에 int형 값으로 바꿀 때, 48을 빼주면
    // 10으로 쉽게 바꿔줄 수 있기 때문임
    // 이는 ':'가 아스키코드 값으로 58이라는데에 대한 배경지식이 필요함
    for(int i=0; i<len; i++){
        if(dartResult[i] == '1' && dartResult[i+1]=='0'){
            dartResult[i]= ':';
            dartResult.erase(i+1,1);
        }
    }
    
    int dartlen = dartResult.length();
    
    for(int i=0; i<dartlen; i++){
        
	// dartResult[i] == 'S'인 경우는
	// dartResult[i-1]의 값을 그대로 더해주면 됨 
        if(dartResult[i] == 'S'){
            answer += pow((dartResult[i-1]-48),1);
        }
	
	// dartResult[i] == 'D'인 경우는
	// dartResult[i-1]의 값을 제곱해서 더해주면 됨    
	else if(dartResult[i] == 'D'){
            answer += pow((dartResult[i-1]-48),2);
        }
	
	// dartResult[i] == 'T'인 경우는
	// dartResult[i-1]의 값을 세제곱해서 더해주면 됨
	else if(dartResult[i] == 'T'){
            answer += pow((dartResult[i-1]-48),3);
        }
	    
	    
	    
	// dartResult[i] == '*'인 경우는    
	// dartResult[i-1] 과 dartResult[i-3]에 대해서 각각 계산함    
	else if(dartResult[i] == '*'){
            
	     // dartResult[i-1] == 'S' or 'D' or 'T'에 따라서 값을 더해줌 
             // 여기서 1회만 더하는 이유는
	     // 기존에 이미 1회 더했기 때문임
	     // 여기서 1회 더하는 것만으로 2배를 나타낼 수 있음 
             if(dartResult[i-1] == 'S'){
                answer += pow((dartResult[i-2]-48),1);
             }else if(dartResult[i-1] == 'D'){
                answer += pow((dartResult[i-2]-48),2);
             }else if(dartResult[i-1] == 'T'){
                answer += pow((dartResult[i-2]-48),3);
             }
        
        // i == 2인 경우는 continue를 함
        // continue를 하는 이유는 i == 2 인 경우는 
        // 해당 점수만 2배로 만들어줄 수 있고,
	// 그 이전의 점수는 2배로 만들어줄 수 없기 때문임 
        if(i == 2){
            continue;
        }
         
        // dartResult[i-3] == 'S' or 'D' or 'T'에 따라서 값을 더해줌
	// 여기서 1회만 더하는 이유는
	// 기존에 이미 1회만 더했기 때문임
	// 여기서 1회 더하는 것만으로 2배를 나타낼 수 있음 
		
	// dartResult[i] == '*' and dartResult[i-3] == '#'일 때는,
	// 변수 temp에 저장된 값만큼 빼줌
	// 이렇게 하는 이유는 이미 앞에서 '#'일 때, 한 번 빼줬기 때문에,
	// 여기서는 -2배를 하는 것이므로, 한 번만 더 빼주면 됨 
        if(dartResult[i-3] == 'S'){
            answer += pow((dartResult[i-4]-48),1);
        }else if(dartResult[i-3] == 'D'){
            answer += pow((dartResult[i-4]-48),2);
        }else if(dartResult[i-3] == 'T'){
            answer += pow((dartResult[i-4]-48),3);
        }else if(dartResult[i-3] == '#'){
            answer -= temp;
        }
	
	// dartResult[i-1] == '*' and dartResult[i-3] == '*' 이면
	// dartResult[i-5]에 있는 점수는 중첩되어 계산이 됨
	// 이 경우, dartResult[i-5]에 있는 정수는 이미 2번 계산 되었으므로
	// 2번 계산한 값을 추가해주면 됨
	// 그러면 총 4번 계산한 것으로 계산이 됨 
	else if (dartResult[i - 3] == '*') {
				if (dartResult[i - 4] == 'S') {
					answer += 2*pow((dartResult[i - 5] - 48), 1);
				}
				else if (dartResult[i - 4] == 'D') {
					answer += 2*pow((dartResult[i - 5] - 48), 2);
				}
				else if (dartResult[i - 4] == 'T') {
					answer += 2*pow((dartResult[i - 5] - 48), 3);
				}
		}
            
        }
	    
	// dartResult[i] == '#'인 경우는 이전 점수를 -로 만듦
	// 따라서 dartResult[i-2]가 이미 더해져있기 때문에
	// 2배를 한 값을 빼줌
	// 그리고 변수 temp에 dartResult[i-2]를 계산한 값을 저장함
	// 변수 temp에 저장하는 이유는 
	// 이후에 dartResult[i] == '*'일 때, 활용하기 위함임 
	else if(dartResult[i] == '#'){
            
            if(dartResult[i-1]=='S'){
                answer -= 2*pow((dartResult[i-2]-48),1);
                temp = pow(dartResult[i-2]-48,1);
            }else if(dartResult[i-1]=='D'){
                answer -= 2*pow((dartResult[i-2]-48),2);
                temp = pow(dartResult[i-2]-48,2);
            }else if(dartResult[i-1]=='T'){
                answer -= 2*pow((dartResult[i-2]-48),3);
                temp = pow(dartResult[i-2]-48,3);
            }
            
        }
    }
    
    // 결과값인 answer를 리턴함 	
    return answer;
    
    
}
