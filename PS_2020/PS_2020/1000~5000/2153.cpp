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
  char str[21];
  int sum = 0;
  scanf("%s", str);
  for (int i = 0; i < strlen(str); i++) {
    if (isupper(str[i])) {
      sum += str[i] - 'A' + 1;

    } else {
      sum += str[i] - 'a' + 1;
    }
  }
  if (sum < 2) {
    printf("It is a prime word.\n");
    return 0;
  }
  for (int i = 2; i < sum; i++) {
    if (sum % i == 0) {
      printf("It is not a prime word.\n");
      return 0;
    }
  }
  printf("It is a prime word.\n");
}