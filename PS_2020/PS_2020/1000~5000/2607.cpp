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
int arr[26], arr2[26];

int main() {
  int n, cnt = 0;
  string temp, str;
  vector<string> v;
  scanf("%d", &n);
  cin >> str;
  for (int i = 0; i < n - 1; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  for (int i = 0; i < str.length(); i++) {
    arr[str[i] - 'A']++;
  }
  for (int i = 0; i < v.size(); i++) {
    int sum = 0;
    memset(arr2, 0, sizeof(arr2));
    for (int k = 0; k < v[i].length(); k++) {
      arr2[v[i][k] - 'A']++;
    }
    for (int k = 0; k < 26; k++) {
      sum += abs(arr[k] - arr2[k]);
    }
    if (sum < 2 || (sum == 2 && str.length() == v[i].length())) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}