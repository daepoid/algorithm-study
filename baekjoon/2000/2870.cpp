//
// Created by 박세현 on 2023/04/04.
//


#include "bits/stdc++.h"

using namespace std;


int N;
vector<string> v;

void addNumber(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] != '0') {
            num = num.substr(i);
            break;
        }
    }

    if (num[0] == '0') {
        num = "0";
    }

    if (num.length() != 0) {
        v.push_back(num);
    }
}

bool comp(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
    }
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string str;
    for (int k = 0; k < N; k++) {
        cin >> str;
        string num = "";
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i])) {
                num += str[i];
                if (i == str.length() - 1) {
                    addNumber(num);
                    num = "";
                }
            } else {
                addNumber(num);
                num = "";
            }
        }
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}