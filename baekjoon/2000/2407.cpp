//
// Created by SeHyun on 2023-01-11.
//


#include "bits/stdc++.h"

using namespace std;

string my_sum(string a, string b) {
    string stra = "", strb = "", answer = "";
    if (a.size() > b.size()) {
        for (int i = 0; i < a.size() - b.size(); i++) {
            strb += "0";
        }
    } else if (a.size() < b.size()) {
        for (int i = 0; i < b.size() - a.size(); i++) {
            stra += "0";
        }
    }
    stra += a;
    strb += b;
    reverse(stra.begin(), stra.end());
    reverse(strb.begin(), strb.end());
    int upper = 0;
    for (int i = 0; i < a.size(); i++) {
        int tempa = stra[i] - '0';
        int tempb = strb[i] - '0';
        upper = (tempa + tempb + upper) / 10;
        answer += to_string((tempa + tempb) % 10);
    }
    if (upper != 0) {
        answer += to_string(upper);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

string my_multiple(string a, string b) {
    string answer;
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
        }
    }
    return answer;
}

int main() {
    string answer, n, m;
    cin >> n >> m;
    answer = my_sum(n, m);
    cout << answer << "\n";
}