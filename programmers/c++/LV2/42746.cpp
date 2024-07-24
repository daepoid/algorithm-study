#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    string A = to_string(a);
    string B = to_string(b);
    return A + B > B + A ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";    
    sort(numbers.begin(), numbers.end(), compare);
    for(int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i]);
    }
    if(answer[0] == '0'){
        return "0";
    }
    return answer;
}