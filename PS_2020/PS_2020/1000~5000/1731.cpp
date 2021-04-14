#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  float temp;
  vector<float> arr;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%f", &temp);
    arr.push_back(temp);
  }
  if (arr[1] - arr[0] == arr[arr.size() - 1] - arr[arr.size() - 2]) {
    printf("%.0f\n", arr[arr.size() - 1] + arr[1] - arr[0]);
  } else {
    printf("%.0f\n", arr[arr.size() - 1] * arr[1] / arr[0]);
  }
}