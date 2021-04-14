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
  string str, keyword, temp = "";
  cin >> str >> keyword;
  for (int i = 0; i < str.length(); i++) {
    if (!isdigit(str[i])) {
      temp += str[i];
    }
  }
  if (temp.find(keyword) != -1) {
    printf("1\n");
  } else {
    printf("0\n");
  }
}