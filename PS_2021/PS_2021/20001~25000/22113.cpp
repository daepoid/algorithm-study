#include <bits/stdc++.h>
#define MAX 111
using namespace std;

int N, M, sum = 0;
vector<int> v;
int board[MAX][MAX];

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    int temp;
    scanf("%d", &temp);
    v.push_back(temp);
  }
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < v.size() - 1; i++) {
    int now = v[i];
    int next = v[i + 1];
    int val = board[now][next];
    sum += val;
  }
  printf("%d\n", sum);
}