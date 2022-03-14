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
  int n, k;
  char str[100];
  vector<int> v;
  scanf("%d %d", &n, &k);
  scanf("%s", str);
  string temp;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ',') {
      v.push_back(stoi(temp));
      temp = "";
    } else {
      temp += str[i];
    }
  }
  v.push_back(stoi(temp));
  while (k-- > 0) {
    vector<int> arr;
    for (int i = 0; i < v.size() - 1; i++) {
      arr.push_back(v[i + 1] - v[i]);
    }
    v.erase(v.begin(), v.end());
    v = arr;
  }
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      printf("%d\n", v[i]);
    } else {
      printf("%d,", v[i]);
    }
  }
}
