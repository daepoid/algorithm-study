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
  int num, n;
  double len, a, b, fly;
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d %lf %lf %lf %lf", &num, &len, &a, &b, &fly);
    printf("%d %lf\n", num, len / (a + b) * fly);
  }
}