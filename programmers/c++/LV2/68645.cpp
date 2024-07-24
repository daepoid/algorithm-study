#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int board[MAX][MAX];

vector<int> solution(int n) {
    vector<int> answer;
    int y = 0, x = 0, cnt = 1;
    for(int k = 0; k < (n - 1) / 3 + 1; k++) {
        for(int i = y; i < n - x; i++) {
            board[i][x] = cnt++;
        }

        for(int i = x + 1; i < n - y; i++) {
            board[n - x - 1][i] = cnt++;
        }
        
        for(int i = n - x - 2, j = n - y - 2; y < i && x < j; i--, j--) {
            board[i][j] = cnt++;
        }
        
        y += 2;
        x += 1;
    }

    for(int i = 0; i < n; i++)  {
        for(int j = 0; j < i + 1; j++) {
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}