#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<string> gems) {
    int left = 0, right = 0;
    set<string> sets(gems.begin(), gems.end());
    map<string, int> m;
    vector<int> answer = {0, 0};

    for(auto name: gems) {
        m[name]++;
        if (m.size() == sets.size()) {
            break;
        }
        right++;
    }

    answer[0] = left + 1;
    answer[1] = right + 1;

    while(right < gems.size()) {
        string key = gems[left];
        m[key]--;
        left++;

        if(m[key] == 0) {
            right++;
            for(; right < gems.size(); right++) {
                m[gems[right]]++;
                if (key == gems[right]) {
                    break;
                }
            }
        }
        if(answer[1] - answer[0] > right - left) {
            answer[0] = left + 1;
            answer[1] = right + 1;
        }
    }
    return answer;
}

int main() {
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> ans = solution(gems);

    for(int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}