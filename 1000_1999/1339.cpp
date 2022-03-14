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

int n, num = 9, sum;
int alpha[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = str.length() - 1; j >= 0; j--) {
      alpha[str[j] - 'A'] += pow(10, str.length() - 1 - j);
    }
  }
  sort(alpha, alpha + 26, greater<int>());
  for (int i = 0; i < 26; i++) {
    if (alpha[i] == 0) {
      break;
    }
    sum += alpha[i] * num;
    num--;
  }
  printf("%d\n", sum);
}