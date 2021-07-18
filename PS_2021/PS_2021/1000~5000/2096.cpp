#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int N;
int board[MAX][MAX];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &board[i][j]);
    }
  }
}