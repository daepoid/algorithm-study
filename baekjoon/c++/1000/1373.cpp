#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int temp = 0;
  string str;
  cin >> str;
  if (str.length() % 3 == 1) {
    str = "00" + str;
  } else if (str.length() % 3 == 2) {
    str = "0" + str;
  }
  for (int i = 0; i < str.length(); i += 3) {
    temp = 0;
    if (str[i] == '1') {
      temp += 4;
    }
    if (str[i + 1] == '1') {
      temp += 2;
    }
    if (str[i + 2] == '1') {
      temp += 1;
    }
    printf("%d", temp);
  }
  printf("\n");
}