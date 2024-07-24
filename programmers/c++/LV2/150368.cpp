#include<bits/stdc++.h>
#define MAX 8
using namespace std;

int temp_discount[MAX];
vector<int> answer = { 0, 0 };

void sol(int idx, vector<vector<int>>& users, vector<int>& emoticons) {
    if(idx == emoticons.size()) {
        int total_join = 0, total_sum = 0;
        for(int i = 0; i < users.size(); i++) {
            int user_sum = 0;
            for(int j = 0; j < emoticons.size(); j++) {
                if(users[i][0] <= temp_discount[j]) {
                    user_sum += emoticons[j] * (100.0 - temp_discount[j]) / 100.0;
                }
            }
            if(users[i][1] <= user_sum) {
                total_join++;
            } else {
                total_sum += user_sum;
            }
        }
        if((answer[0] < total_join) || (answer[0] == total_join && answer[1] < total_sum)) {
            answer[0] = total_join;
            answer[1] = total_sum;
        }
        return;
    }
    
    for(int i = 10; i <= 40; i += 10) {
        temp_discount[idx] = i;
        sol(idx + 1, users, emoticons);
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    sol(0, users, emoticons);
    return answer;
}