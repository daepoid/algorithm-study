//
// Created by 박세현 on 2023/04/05.
//

#include "bits/stdc++.h"

#define MAX 51
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int board[MAX][MAX];
int answer = INF;
vector<pair<int, int> > v;
deque<pair<int, int> > dq;

void close_shop(int num, int idx) {
    if (num == M) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    int min_dist = INF;
                    for (int k = 0; k < dq.size(); k++) {
                        min_dist = min(min_dist, abs(i - dq[k].first) + abs(j - dq[k].second));
                    }
                    sum += min_dist;
                }
            }
        }
        answer = min(answer, sum);
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        dq.push_back(v[i]);
        close_shop(num + 1, i + 1);
        dq.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 2) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    close_shop(0, 0);
    printf("%d\n", answer);
}