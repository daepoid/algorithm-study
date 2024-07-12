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
  int n;
  scanf("%d", &n);
  while (n-- > 0) {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    do {
      cout << str << "\n";
    } while (next_permutation(str.begin(), str.end()));
  }
}