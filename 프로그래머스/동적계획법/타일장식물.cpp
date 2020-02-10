#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    
    long long a[100]={0};
    
    a[1] = 4;
    a[2] = 6;
    
    for(int i=3; i<=N; i++){
        a[i] = a[i-1]+a[i-2];
    }
    
    long long answer = a[N];
    
    return answer;
}
