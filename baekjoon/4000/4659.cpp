//
// Created by 박세현 on 2023/04/04.
//


#include "bits/stdc++.h"

using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (true) {
        cin >> str;
        if (str == "end") {
            break;
        }
        bool flag_v = false, flag = true;
        int cnt_v = 0, cnt_nv = 0;
        char bf = 'A';
        for (int i = 0; i < str.length(); i++) {
            if (is_vowel(str[i])) {
                flag_v = true;
                cnt_v++;
                cnt_nv = 0;
            } else {
                cnt_nv++;
                cnt_v = 0;
            }
            if (cnt_v > 2 || cnt_nv > 2) {
                flag = false;
            }

            if (bf == str[i] && bf != 'e' && bf != 'o') {
                flag = false;
            }
            bf = str[i];
        }
        if (!flag_v) {
            flag = false;
        }
        cout << "<" << str << "> is " << (flag ? "" : "not ") << "acceptable.\n";
    }
}