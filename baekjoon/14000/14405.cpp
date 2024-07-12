//
// Created by 박세현 on 2023/05/12.
//


#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    while (str.length() > 0) {
        if (str.length() >= 2 && str.substr(0, 2) == "pi" || str.substr(0, 2) == "ka") {
            str = str.substr(2);
        } else if (str.length() >= 3 && str.substr(0, 3) == "chu") {
            str = str.substr(3);
        } else {
            break;
        }
    }

    if (str.length() == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}