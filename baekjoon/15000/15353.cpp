//
// Created by 박세현 on 2023/05/12.
//

#include "bits/stdc++.h"

using namespace std;

string calculate_big_number(string A, string B) {
    int sum = 0;
    string answer = "";
    while (A.length() > 0 || B.length() > 0 || sum > 0) {
        if (A.length() > 0) {
            sum += (A.back() - '0');
            A.pop_back();
        }
        if (B.length() > 0) {
            sum += (B.back() - '0');
            B.pop_back();
        }
        answer += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    cout << calculate_big_number(A, B) << "\n";
}