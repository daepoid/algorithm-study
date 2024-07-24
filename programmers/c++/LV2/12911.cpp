#include <bits/stdc++.h>
using namespace std;

string tobi(int num){
    string answer = "";    
    while(num > 0){
        answer += (num % 2) + '0';
        num /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int cnt_one(string num){
    int cnt = 0;
    for(int i = 0; i < num.length(); i++){
       if(num[i] == '1'){
           cnt++;
       }
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    string num = tobi(n);
    int n_one = cnt_one(num);
    for(int i = n + 1;; i++){
        if(n_one == cnt_one(tobi(i))){
            return i;
        }
    }
}

int main () {
    int n = 78;
    int result = solution(n);
    cout << result << "\n";
}