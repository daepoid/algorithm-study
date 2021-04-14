#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> up, down, robot;

int count_zero() {
  int cnt = 0;
  for (int i = 0; i < up.size(); i++) {
    if (up[i] == 0) {
      cnt++;
    }
  }
  for (int i = 0; i < down.size(); i++) {
    if (down[i] == 0) {
      cnt++;
    }
  }
  return cnt;
}

void move_robot() {}

void add_robot() {}

int main() {
  int temp, answer = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    up.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    down.push_back(temp);
  }
  reverse(down.begin(), down.end());

  while (true) {
    if (count_zero() >= k) {
      break;
    }
    rotate_belt();
    move_robot();
    add_robot();
    answer++;
  }
  printf("%d\n", answer);
}