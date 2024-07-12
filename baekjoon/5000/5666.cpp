#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  char str[101];
  int i = 0;
  float a = 0, b = 0;
  while (cin.getline(str, 101)) {
    a = 0;
    b = 0;
    for (i = 0; str[i] != ' '; i++) {
      a = a * 10 + str[i] - '0';
    }
    for (i = i + 1; str[i] != '\0'; i++) {
      b = b * 10 + str[i] - '0';
    }
    printf("%.2f\n", a / b);
  }
}