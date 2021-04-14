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
  char str[101];
  int sum = 0, temp;
  while (scanf("%s %d", str, &temp) != EOF) {
    sum += temp;
  }
  printf("총합 : %d원\n", sum);
}