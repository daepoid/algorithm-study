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
  cin >> num;
  if (num == "1") {
    printf("NO\n");
    return 0;
  }
  for (int i = 0; i < num.length(); i++) {
    string temp1 = num.substr(0, i);
    string temp2 = num.substr(i, num.length());
    int temp1_sum = 1, temp2_sum = 1;
    for (int j = 0; j < temp1.length(); j++) {
      temp1_sum *= (temp1[j] - '0');
    }
    for (int j = 0; j < temp2.length(); j++) {
      temp2_sum *= (temp2[j] - '0');
    }
    if (temp1_sum == temp2_sum) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}