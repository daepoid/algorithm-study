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
    int temp;
    scanf("%d", &temp);
    for (int i = 0; i < temp; i++) {
      for (int j = 0; j < temp; j++) {
        if (i == 0 || i == temp - 1) {
          printf("#");
        } else if (j == 0 || j == temp - 1) {
          printf("#");
        } else {
          printf("J");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}