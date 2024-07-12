//
// Created by 박세현 on 2023/05/11.
//


#include "bits/stdc++.h"

using namespace std;


int T, N;
string P;
deque<int> dq;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T-- > 0) {
        dq.clear();
        string temp;
        cin >> P >> N >> temp;
        int curr = 0;
        for (int i = 0; i < temp.length(); i++) {
            if (isdigit(temp[i])) {
                curr = curr * 10 + (temp[i] - '0');
            } else {
                if (curr != 0) {
                    dq.push_back(curr);
                    curr = 0;
                }
            }
        }
        // 필요 옶을 것 같음
        if (curr > 0) {
            dq.push_back(curr);
        }

        bool dir = false, err_flag = false;

        for (char ch: P) {
            if (ch == 'R') {
                dir = !dir;
            } else if (ch == 'D') {
                if (dq.empty()) {
                    err_flag = true;
                    break;
                }
                if (dir) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        if (err_flag) {
            cout << "error\n";
        } else {
            string answer = "[";
            while (!dq.empty()) {
                if (dir) {
                    answer += to_string(dq.back());
                    dq.pop_back();
                } else {
                    answer += to_string(dq.front());
                    dq.pop_front();
                }
                if (!dq.empty()) {
                    answer += ",";
                }
            }
            answer += "]";
            cout << answer << "\n";
        }
    }
}