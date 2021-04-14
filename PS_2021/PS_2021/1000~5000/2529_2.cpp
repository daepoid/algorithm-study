#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int k, temp;
char str[3];
vector<char> sign;
vector<int> answer[2];

bool iscorrect(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    if (sign[i] == '<' && arr[i] > arr[i + 1]) {
      return false;
    } else if (sign[i] == '>' && arr[i] < arr[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%s", &str);
    sign.push_back(str[0]);
  }
  for (int i = 0; i < k + 1; i++) {
    answer[0].push_back(9 - i);
    answer[1].push_back(i);
  }

  do {
    if (iscorrect(answer[0])) {
      break;
    }
  } while (prev_permutation(answer[0].begin(), answer[0].end()));

  do {
    if (iscorrect(answer[1])) {
      break;
    }
  } while (next_permutation(answer[1].begin(), answer[1].end()));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (j == k) {
        printf("%d\n", answer[i][j]);
      } else {
        printf("%d", answer[i][j]);
      }
    }
  }
}