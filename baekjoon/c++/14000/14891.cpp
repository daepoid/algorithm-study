#include <bits/stdc++.h>
using namespace std;

vector<int> gears[4];

void rotate(int n, int dir) {
  vector<int> temp;
  if (dir == 1) {
    temp.push_back(gears[n][7]);
    for (int i = 0; i < 7; i++) {
      temp.push_back(gears[n][i]);
    }
    gears[n] = temp;
  } else if (dir == -1) {
    for (int i = 1; i < 8; i++) {
      temp.push_back(gears[n][i]);
    }
    temp.push_back(gears[n][0]);
    gears[n] = temp;
  }
}

void sol(int n, int dir) {
  if (n == 0) {
    if (gears[n][2] != gears[n + 1][6]) {
      if (gears[n + 1][2] != gears[n + 2][6]) {
        if (gears[n + 2][2] != gears[n + 3][6]) {
          rotate(n, dir);
          rotate(n + 1, -dir);
          rotate(n + 2, dir);
          rotate(n + 3, -dir);
        } else {
          rotate(n, dir);
          rotate(n + 1, -dir);
          rotate(n + 2, dir);
        }
      } else {
        rotate(n, dir);
        rotate(n + 1, -dir);
      }
    } else {
      rotate(n, dir);
    }
  } else if (n == 1) {
    if (gears[n - 1][2] != gears[n][6]) {
      rotate(n - 1, -dir);
    }
    if (gears[n][2] != gears[n + 1][6]) {
      if (gears[n + 1][2] != gears[n + 2][6]) {
        rotate(n, dir);
        rotate(n + 1, -dir);
        rotate(n + 2, dir);
      } else {
        rotate(n, dir);
        rotate(n + 1, -dir);
      }
    } else {
      rotate(n, dir);
    }
  } else if (n == 2) {
    if (gears[n][2] != gears[n + 1][6]) {
      rotate(n + 1, -dir);
    }
    if (gears[n - 1][2] != gears[n][6]) {
      if (gears[n - 2][2] != gears[n - 1][6]) {
        rotate(n, dir);
        rotate(n - 1, -dir);
        rotate(n - 2, dir);
      } else {
        rotate(n, dir);
        rotate(n - 1, -dir);
      }
    } else {
      rotate(n, dir);
    }
  } else if (n == 3) {
    if (gears[n - 1][2] != gears[n][6]) {
      if (gears[n - 2][2] != gears[n - 1][6]) {
        if (gears[n - 3][2] != gears[n - 2][6]) {
          rotate(n, dir);
          rotate(n - 1, -dir);
          rotate(n - 2, dir);
          rotate(n - 3, -dir);
        } else {
          rotate(n, dir);
          rotate(n - 1, -dir);
          rotate(n - 2, dir);
        }
      } else {
        rotate(n, dir);
        rotate(n - 1, -dir);
      }
    } else {
      rotate(n, dir);
    }
  }
}

int main() {
  char s[10];
  int k, n, dir;
  int answer = 0;
  for (int i = 0; i < 4; i++) {
    scanf("%s", s);
    for (int j = 0; j < 8; j++) {
      gears[i].push_back(s[j] - '0');
    }
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &n, &dir);
    sol(n - 1, dir);
  }
  for (int i = 0; i < 4; i++) {
    if (gears[i][0] == 1) {
      answer += pow(2, i);
    }
  }
  printf("%d\n", answer);
}