#include <bits/stdc++.h>
#define MAX 100011
using namespace std;

vector<int> v[MAX];
int answer[MAX];

int main() {
  int N;
  int a, b;
  queue<int> q;
  q.push(1);

  scanf("%d", &N);

  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    for (int i : v[num]) {
      if (answer[i] == 0) {
        answer[i] = num;
        q.push(i);
      }
    }
  }

  for (int i = 2; i < N + 1; i++) {
    printf("%d\n", answer[i]);
  }
}