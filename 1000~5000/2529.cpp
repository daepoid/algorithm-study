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

int k;
char temp[4];
vector<char> signs;
bool flag = false;

bool is_correct_permutation(vector<int> arr) {
  for (int i = 0; i < signs.size(); i++) {
    if (signs[i] == '<') {
      if (arr[i] > arr[i + 1]) {
        return false;
      }
    } else if (signs[i] == '>') {
      if (arr[i] < arr[i + 1]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<int> max_arr, min_arr;

  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%s", temp);
    signs.push_back(temp[0]);
  }
  for (int i = 0; i < k + 1; i++) {
    max_arr.push_back(9 - i);
    min_arr.push_back(i);
  }
  do {
    if (is_correct_permutation(max_arr)) {
      break;
    }
  } while (prev_permutation(max_arr.begin(), max_arr.end()));

  do {
    if (is_correct_permutation(min_arr)) {
      break;
    }
  } while (next_permutation(min_arr.begin(), min_arr.end()));

  for (int i = 0; i < max_arr.size(); i++) {
    if (i == max_arr.size() - 1) {
      printf("%d\n", max_arr[i]);
    } else {
      printf("%d", max_arr[i]);
    }
  }
  for (int i = 0; i < min_arr.size(); i++) {
    if (i == min_arr.size() - 1) {
      printf("%d\n", min_arr[i]);
    } else {
      printf("%d", min_arr[i]);
    }
  }
}