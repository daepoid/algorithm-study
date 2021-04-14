#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> arr, answer;
vector<int> board[MAX];
vector<bool> visited[MAX];

int main() {
  int n, temp, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    board[a].push_back(b);
    board[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    answer.push_back(temp);
  }

  bfs();
}