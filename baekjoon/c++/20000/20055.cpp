#include <bits/stdc++.h>
#define MAX 220
using namespace std;

int N, K, start, last, cnt, answer;
int belt[MAX];
bool visitied[MAX];
queue<int> robot;

void move_belt() {
  start--;
  last--;
  if (start < 1)
    start = 2 * N;
  if (last < 1)
    last = 2 * N;
}

void move_robot() {
  for (int i = 0; i < robot.size(); i++) {
    int curr = robot.front();
    visitied[curr] = false;
    robot.pop();

    if (curr == last) {
      continue;
    }

    int next = curr + 1;
    if (next > 2 * N) {
      next = 1;
    }
    if (belt[next] >= 1 && visitied[next] == false) {
      belt[next]--;
      if (belt[next] == 0)
        cnt++;
      if (next == last)
        continue;
      visitied[next] = true;
      robot.push(next);
    } else {
      visitied[curr] = true;
      robot.push(curr);
    }
  }
}

void add_robot() {
  if (visitied[start] == false && belt[start] >= 1) {
    visitied[start] = true;
    belt[start]--;
    robot.push(start);

    if (belt[start] == 0)
      cnt++;
  }
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= 2 * N; i++) {
    scanf("%d", &belt[i]);
  }

  start = 1;
  last = N;

  while (cnt < K) {
    answer++;
    move_belt();
    move_robot();
    add_robot();
  }
  printf("%d\n", answer);
  return 0;
}