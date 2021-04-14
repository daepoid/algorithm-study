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
  string num;
  int gap = 0;
  bool flag = true;
  cin >> num;
  gap = num[1] - num[0];
  for (int i = 2; i < num.length(); i++) {
    if (gap != num[i] - num[i - 1]) {
      flag = false;
    }
  }
  if (flag) {
    printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n");
  } else {
    printf("흥칫뿡!! <(￣ ﹌ ￣)>\n");
  }
}