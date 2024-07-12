#include "bits/stdc++.h"
#define MAX 101
using namespace std;

int N, K;
deque<int>board[MAX];

bool isFinish() {
    int max_val = -1;
    int min_val = 2100000000;
    for(int i = 0; i < N; i++) {
        max_val = max(max_val, board[0][i]);
        min_val = min(min_val, board[0][i]);
    }
    return max_val - min_val <= K;
}

void addFishes() {
    int min = *min_element(board[0].begin(), board[0].end());
    for(int i = 0; i < N; i++) {
        if(board[0][i] == min) {
            board[0][i]++;
        }
    }
}

bool isBuildable(int width, int height) {
    return board[0].size() - width >= height;
}

void buildBowls() {
    deque<int> temp[MAX];
    int width = 1;
    int height = 1;
    while(isBuildable(width, height)) {
        for(int i = 0; i < width; i++) {
            for (int j = height - 1; j >= 0; j--) {
                temp[width - i].push_front(board[j].front());
                board[j].pop_front();
            }
        }
        for(int i = 1; i < width + 1; i++) {
            board[i] = temp[i];
            temp[i].clear();
        }

        int t_num = height;
        height = width + 1;
        width = t_num;
    }
}

void divideFishes() {
    deque<int> temp[MAX];
    int height;
    for(height = 0; height < N; height++) {
        if(board[height].size() == 0) {
            break;
        }
        temp[height] = board[height];
    }

    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < board[i].size(); j++) {
            
            // 오른쪽 비교
            if(j + 1 < board[i].size()) {
                int d = abs(board[i][j] - board[i][j + 1]) / 5;
                if (d > 0) {
                    if(board[i][j] > board[i][j + 1]) {
                        temp[i][j] -= d;
                        temp[i][j + 1] += d;
                    } else {
                        temp[i][j] += d;
                        temp[i][j + 1] -= d;
                    }
                }
            }

            // 아래 비교
            if(i - 1 >= 0) {
                int d = abs(board[i][j] - board[i - 1][j]) / 5;
                if (d > 0) {
                    if (board[i][j] > board[i - 1][j]) {
                        temp[i][j] -= d;
                        temp[i - 1][j] += d;
                    }
                    else {
                        temp[i][j] += d;
                        temp[i - 1][j] -= d;
                    }
                }
            }
        }        
    }
    
    for (int i = 0; i < N; i++) {
        if (temp[i].size() == 0) {
            break;
        }
        board[i] = temp[i];
    }
}

void flatBowls() {
    deque<int> temp;
    while(board[0].size() > 0) {
        for(int i = 0; i < N; i++) {
            if(board[i].size() < 1) {
                break;
            }
            temp.push_back(board[i].front());
            board[i].pop_front();
        }
    }
    for(int i = 1; i < N; i++) {
        if(board[i].size() == 0) {
            break;
        }
        board[i].clear();
    }
    board[0] = temp;
}

void foldBowls() {
    int size = board[0].size() / 4;

    for(int i = 0; i < size; i++) {
        board[1].push_front(board[0].front());
        board[0].pop_front();
    }

    for (int i = 0; i < size; i++) {
        board[2].push_back(board[0].front());
        board[0].pop_front();
    }

    for (int i = 0; i < size; i++) {
        board[3].push_front(board[0].front());
        board[0].pop_front();
    }
}


int main() {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        board[0].push_back(temp);
    }

    int answer = 0;
    while(!isFinish()) {
        addFishes();
        buildBowls();
        divideFishes();
        flatBowls();
        foldBowls();
        divideFishes();
        flatBowls();

        answer++;
    }

    printf("%d\n", answer);
}
