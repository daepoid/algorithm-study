//
// Created by 박세현 on 2023/04/02.
//

#include "bits/stdc++.h"
using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T-- > 0) {
        cin >> N;
        map<string, int> counts;
        string name, cloth_type;
        for(int i = 0; i < N; i++) {
            cin >> name >> cloth_type;
            counts[cloth_type]++;
        }
        int answer = 1;
        for(auto ty: counts) {
            answer *= (ty.second + 1);
        }
        cout << answer - 1 << "\n";
    }
}