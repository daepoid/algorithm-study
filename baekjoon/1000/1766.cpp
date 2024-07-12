#include <bits/stdc++.h>
#define MAX 32011
using namespace std;

int N, M;
vector<int> board[MAX];
int count[MAX];
vector<int> answer;

void solutions() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (count[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int num = pq.top();
        pq.pop();
        answer.push_back(num);

        for (int i = 0; i < board[num].size(); i++) {
            int next_num = board[num][i];
            count[next_num]--;
            if (count[next_num] == 0) {
                pq.push(next_num);
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        if (i != answer.size() - 1) {
            printf("%d ", answer[i]);
        }
        else {
            printf("%d\n", answer[i]);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        board[a].push_back(b);
        count[b]++;
    }
    solutions();
}