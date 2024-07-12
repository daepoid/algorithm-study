//
// Created by 박세현 on 2023/05/12.
//

#include "bits/stdc++.h"

#define MAX 200001
using namespace std;

int N, answer;
string str;
stack<int> stk;
bool visited[MAX];


int main() {
    cin >> N >> str;
    for (int i = 0; i < N; i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else {
            if (!stk.empty()) {
                int idx = stk.top();
                visited[idx] = true;
                visited[i] = true;
                stk.pop();
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            cnt++;
        } else {
            answer = max(answer, cnt);
            cnt = 0;
        }
    }
    answer = max(answer, cnt);
    cout << answer << "\n";
}