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

int main() {
  int n, temp;
  vector<int> arr, ans;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  for (int i = 0; i < arr.size(); i++) {
    if (i == 0) {
      printf("%d", arr[0]);
    } else {
      printf("%d", arr[i] * (i + 1) - arr[i - 1] * i);
    }

    if (i == arr.size() - 1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
}