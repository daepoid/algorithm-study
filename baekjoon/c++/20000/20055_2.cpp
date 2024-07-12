#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct STATE {
  bool onRobot;
  int life;
};

int N, K, answer = 1;
STATE belt_up[MAX + 1];
STATE belt_down[MAX + 1];
bool flag = true;

void rotate_belt() {
  STATE temp = {belt_up[N - 1].onRobot, belt_up[N - 1].life};
  for (int i = N - 1; i > 0; i--) {
    belt_up[i] = belt_up[i - 1];
  }
  belt_up[0] = belt_down[0];
  for (int i = 0; i < N - 1; i++) {
    belt_down[i] = belt_down[i + 1];
  }
  belt_down[N - 1] = temp;
  if (belt_up[N - 1].onRobot) {
    belt_up[N - 1].onRobot = false;
  }
}

void move_robot() {
  for (int i = N - 1; i > 0; i--) {
    if (!belt_up[i].onRobot && belt_up[i - 1].onRobot && belt_up[i].life >= 1) {
      belt_up[i].life--;
      belt_up[i].onRobot = true;
      belt_up[i - 1].onRobot = false;
    }
  }
  if (belt_up[N - 1].onRobot) {
    belt_up[N - 1].onRobot = false;
  }
}

void add_robot() {
  if (belt_up[0].life > 0 && !belt_up[0].onRobot) {
    belt_up[0].life--;
    belt_up[0].onRobot = true;
  }
}

void check_end() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (belt_up[i].life <= 0) {
      cnt++;
    }
    if (belt_down[i].life <= 0) {
      cnt++;
    }
  }
  if (K <= cnt) {
    flag = false;
  } else {
    answer++;
  }
}

int main() {
  scanf("%d %d", &N, &K);
  int a;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    belt_up[i].life = a;
    belt_up[i].onRobot = false;
  }
  for (int i = N - 1; i >= 0; i--) {
    scanf("%d", &a);
    belt_down[i].life = a;
    belt_down[i].onRobot = false;
  }

  while (flag) {
    rotate_belt();
    move_robot();
    add_robot();
    check_end();
  }
  printf("%d\n", answer);
}