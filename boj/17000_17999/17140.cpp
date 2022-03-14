#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int board[MAX][MAX], nums[MAX];
int r, c, k;
int max_num = 0, row_max_num, col_max_num, answer = 0;
int nowrow, nowcol;

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second < b.second) {
    return true;
  } else if (a.second > b.second) {
    return false;
  } else {
    return a.first < b.first;
  }
}

void print_board() {
  for (int i = 1; i < nowrow + 1; i++) {
    for (int j = 1; j < nowcol + 1; j++) {
      if (j == nowcol) {
        printf("%d\n", board[i][j]);
      } else {
        printf("%d ", board[i][j]);
      }
    }
  }
}

int main() {
  nowrow = 3;
  nowcol = 3;

  scanf("%d %d %d", &r, &c, &k);

  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  while (true) {
    if (board[r][c] == k) {
      break;
    } else if (answer > 100) {
      answer = -1;
      break;
    }

    if (nowrow >= nowcol) {
      max_num = 0;
      int temp = nowcol;
      for (int i = 1; i < nowrow + 1; i++) {
        vector<pair<int, int>> v;
        memset(nums, 0, sizeof(nums));
        for (int j = 1; j < nowcol + 1; j++) {
          nums[board[i][j]]++;
        }
        for (int j = 1; j < MAX; j++) {
          if (nums[j] != 0) {
            v.push_back(make_pair(nums[j], j));
          }
        }
        sort(v.begin(), v.end());
        for (int j = 1; j < nowcol + 1; j++) {
          board[i][j] = 0;
        }
        int idx = 1;
        for (int j = 0; j < v.size(); j++) {
          board[i][idx++] = v[j].second;
          board[i][idx++] = v[j].first;
        }
        temp = max(temp, idx - 1);
      }
      nowcol = temp;
    } else if (nowrow < nowcol) {
      max_num = 0;
      int temp = nowrow;
      for (int j = 1; j < nowcol + 1; j++) {
        vector<pair<int, int>> v;
        memset(nums, 0, sizeof(nums));
        for (int i = 1; i < nowrow + 1; i++) {
          nums[board[i][j]]++;
        }
        for (int i = 1; i < MAX; i++) {
          if (nums[i] != 0) {
            v.push_back(make_pair(nums[i], i));
          }
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < nowrow + 1; i++) {
          board[i][j] = 0;
        }
        int idx = 1;
        for (int i = 0; i < v.size(); i++) {
          board[idx++][j] = v[i].second;
          board[idx++][j] = v[i].first;
        }
        temp = max(temp, idx - 1);
      }
      nowrow = temp;
    }
    answer++;
  }
  printf("%d\n", answer);
}