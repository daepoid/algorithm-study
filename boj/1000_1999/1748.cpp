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
  long long int sum = 0;
  string n;
  cin >> n;
  int len = int(n.size());
  if (len == 1) {
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i < len; i++) {
    sum += i * 9 * pow(10, i - 1);
  }
  sum += len * (stoi(n) - pow(10, len - 1) + 1);
  cout << sum << endl;
}