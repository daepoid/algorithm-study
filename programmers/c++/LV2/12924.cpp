#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 1;
    if(n % 2 == 1 && n > 1){
        answer++;
    }
    for(int i = 3; i * (i + 1) / 2 <= n; i++){
        int temp = n - (i * (i + 1) / 2);
        if(temp % i == 0){
            answer++;
        }
    }    
    return answer;
}

int main () {
    int n = 15;
    int result = solution(n);
    cout << result << "\n";
}