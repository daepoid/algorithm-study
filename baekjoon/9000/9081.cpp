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
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    string str, temp;
    cin >> str;
    temp = str;
    sort(temp.begin(), temp.end(), greater<char>());
    if (temp == str) {
      cout << temp << "\n";
    } else {
      next_permutation(str.begin(), str.end());
      cout << str << "\n";
    }
  }
}