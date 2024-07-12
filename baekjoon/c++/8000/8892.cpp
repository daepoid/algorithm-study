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
    int n;
    bool flag = false;
    string temp;
    vector<string> arr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      cin >> temp;
      arr.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
      if (flag) {
        break;
      }
      for (int j = 0; j < n; j++) {
        if (i != j) {
          temp = arr[i] + arr[j];
          string temp2 = temp;
          reverse(temp2.begin(), temp2.end());
          if (temp2 == temp) {
            cout << temp2 << "\n";
            flag = true;
            break;
          }
        }
      }
    }
    if (!flag) {
      printf("0\n");
    }
  }
}