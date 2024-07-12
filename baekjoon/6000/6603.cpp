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

int selected[10];
bool visited[13];

void print_arr() {
  for (int i = 1; i < 7; i++) {
    if (i == 6) {
      printf("%d\n", selected[i]);
    } else {
      printf("%d ", selected[i]);
    }
  }
}

void sol(vector<int> arr, int cnt) {
  if (cnt == 7) {
    print_arr();
    return;
  }
  for (int i = cnt - 1; i < arr.size(); i++) {
    if (!visited[i] && selected[cnt - 1] < arr[i]) {
      selected[cnt] = arr[i];
      visited[i] = true;
      sol(arr, cnt + 1);
      selected[cnt + 1] = 0;
      visited[i] = false;
    }
  }
}

int main() {
  int k, temp;
  while (true) {
    vector<int> arr;
    scanf("%d", &k);
    if (k == 0) {
      return 0;
    }
    for (int i = 0; i < k; i++) {
      scanf("%d", &temp);
      arr.push_back(temp);
    }
    sol(arr, 1);
    printf("\n");
  }
}