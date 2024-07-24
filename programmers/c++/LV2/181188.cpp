#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int s = -1, e = -1;
    sort(targets.begin(), targets.end());
    for(int i = 0; i < targets.size(); i++) {
        if(e <= targets[i][0]) {
            s = targets[i][0];
            e = targets[i][1];
            answer++;
        } else {
            e = min(e, targets[i][1]);
        }
    }
    return answer;
}