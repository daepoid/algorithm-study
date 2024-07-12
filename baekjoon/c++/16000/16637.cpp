//
// Created by 박세현 on 2023/04/07.
//


#include "bits/stdc++.h"

using namespace std;


int N, answer = -2100000000;
vector<int> numbers;
vector<char> ops;
string str;

int calc(int a, int b, char ch) {
    if (ch == '+') return a + b;
    else if (ch == '-') return a - b;
    else if (ch == '*') return a * b;
    else {
        cout << "ERROR\n";
        return 0;
    }
}

void dfs(int sum, int idx) {
    if (numbers.size() <= idx) {
        answer = max(answer, sum);
        return;
    }

    dfs(calc(sum, numbers[idx], ops[idx]), idx + 1);

    if (idx + 1 < numbers.size()) {
        int temp_sum = calc(numbers[idx], numbers[idx + 1], ops[idx + 1]);
        dfs(calc(sum, temp_sum, ops[idx]), idx + 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> str;
    ops.push_back('+');

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            numbers.push_back(str[i] - '0');
        } else {
            ops.push_back(str[i]);
        }
    }

    dfs(0, 0);
    cout << answer << "\n";
}