#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, K;
int bowl[MAX][MAX];
int answer = 0;
vector<int> min_value_pos;

void print_board() {
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      printf("%3d ", bowl[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void add_fish() {
  int min_pos = 0;
  for (int i = 0; i < N; i++) {
    min_pos = bowl[0][i] < bowl[0][min_pos] ? i : min_pos;
  }
  bowl[0][min_pos]++;
  for (int i = 0; i < N; i++) {
    if (bowl[0][min_pos] - 1 == bowl[0][i]) {
      bowl[0][i]++;
    }
  }
}

bool buildalbe(int width, int height) {
  if (bowl[0].size() - width < height) {
    return false;
  }
  return true;
}

void build_bowl(int a) {

  while (buildalbe()) {
    copy();
    rotate();
    paste();
  }
}

void build_bowl() {
  int width = 1;
  int height = 1;
  int pivot = 1;
  bool flag = true;

  while (buildalbe(width, height)) {

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        board[][] = board[][];
      }
    }

    if (flag) {
      width++;
      flag = false;
    } else {
      height++;
      flag = true;
    }
  }
}

void move_fish() {}

void sort_bowl() {}

void rebuild_bowl() {}

bool valid_fish_diff() {
  int max_val = max_element(bowl[0].begin(), bowl[0].end());
  int min_val = min_element(bowl[0].begin(), bowl[0].end());
  return (max_val - min_val) <= K;
}

int main() {
  int temp;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &temp);
    bowl[0].push_back(temp);
  }

  while (true) {
    add_fish(); // 1. 물고기 추가

    build_bowl(); // 2. 어항 정리 1
    move_fish();  // 3. 물고기 수 조절
    sort_bowl();  // 4. 어항 일렬 조정

    rebuild_bowl(); // 5. 어항 정리 2
    move_fish();    // 6. 물고기 수 조절
    sort_bowl();    // 7. 어항 일렬 조정

    answer++; // 8. 정리 카운트
    if (valid_fish_diff()) {
      break;
    }
  }
  printf("%d\n", answer);
}