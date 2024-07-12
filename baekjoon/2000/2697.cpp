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
    char num[100], sorted_num[100];
    scanf("%s", num);
    strcpy(sorted_num, num);
    sort(sorted_num, sorted_num + strlen(sorted_num));
    next_permutation(num, num + strlen(num));
    if (strcmp(sorted_num, num) == 0) {
      printf("BIGGEST\n");
    } else {
      printf("%s\n", num);
    }
  }
}