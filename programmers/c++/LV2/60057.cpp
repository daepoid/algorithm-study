#include <bits/stdc++.h>
using namespace std;

vector<string> to_token(string str, int sz)
{
    vector<string> tokens;
    for(int i = 0 ; i < str.length() ; i += sz) {
        tokens.push_back(str.substr(i,sz));
    }
    return tokens;
}

int solution(string s) {
    int answer = s.length();
    int cnt = 1;
    vector<string> tokens;
    string before, new_str;
    
    for(int j = 1 ; j <= s.length() / 2; j++) {
        tokens = to_token(s,j);
        new_str = "";
        before = tokens[0];
        cnt = 1;
        for(int i = 1 ; i < tokens.size() ; i++) {
            if(tokens[i] == before) {
                cnt++;  
            } else {
                if(cnt != 1) {
                    new_str += to_string(cnt);
                }
                new_str += before;
                before = tokens[i];
                cnt = 1;
            }
        }
        if(cnt != 1) {
            new_str += to_string(cnt);
        }
        new_str += before;
        answer = min(answer, (int)new_str.length());
    }
    cout << new_str;

    return answer;
}