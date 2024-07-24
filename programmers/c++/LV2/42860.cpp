#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1;
    int a_len = 0;

    for(int i = 0; i < name.length(); i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        a_len = i + 1;
        while(a_len < len && name[a_len] == 'A'){
            a_len++;
        }

        move = min(move, i * 2 + len - a_len);
        move = min(move, (len - a_len) * 2 + i);
    }

    return answer + move;
}