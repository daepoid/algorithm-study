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

int answer = 0;
void sol(vector<int> arr, int x, int sum) {
  if (arr.size() == 2) {
    return;
  }
  int temp = arr[x - 1] * arr[x + 1];
  arr.erase(arr.begin() + x);
  answer = max(answer, sum + temp);
  for (int i = 1; i < arr.size() - 1; i++) {
    sol(arr, i, sum + temp);
  }
}

int main() {
  vector<int> arr;
  int n, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  for (int i = 1; i < n - 1; i++) {
    sol(arr, i, 0);
  }
  printf("%d\n", answer);
}