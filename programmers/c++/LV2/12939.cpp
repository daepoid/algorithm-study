#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '-' || ('0' <= s[i] && s[i] <= '9')){
            temp += s[i];
        }
        else if(s[i] == ' '){
            num.push_back(atoi(temp.c_str()));
            temp.clear();
        }
    }
    num.push_back(atoi(temp.c_str()));
    sort(num.begin(), num.end());
    answer = answer + to_string(num[0]) + " " + to_string(num[num.size() - 1]);
    return answer;
}

int main () {
    string s = "1 2 3 4";
    string result = solution(s);
    cout << result << "\n";
}