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
  char str[11];
  int a;
  while (scanf("%s %d", &str, &a) != EOF) {
    int len = strlen(str);
    int sum = 1;
    for (int i = 2; i <= len; i++) {
      sum *= i;
    }
    printf("%s %d = ", str, a);
    if (sum < a) {
      printf("No permutation\n");
    } else {
      for (int i = 0; i < a - 1; i++) {
        next_permutation(str, str + len);
      }
      printf("%s\n", str);
    }
  }
}