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
  int tc;
  scanf("%d", &tc);
  string a, b;
  while (tc-- > 0) {
    int arr[26];
    memset(arr, 0, sizeof(arr));
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
      arr[tolower(a[i]) - 'a']++;
    }
    for (int i = 0; i < b.length(); i++) {
      arr[tolower(b[i]) - 'a']--;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (arr[i] != 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << a << " & " << b << " are anagrams." << endl;
    } else {
      cout << a << " & " << b << " are NOT anagrams." << endl;
    }
  }
}