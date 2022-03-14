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
  int t;
  scanf("%d", &t);
  string temp;
  getline(cin, temp);
  while (t-- > 0) {
    string cry;
    getline(cin, cry);
    getline(cin, temp);
    for (int i = 0; i < cry.size(); i++) {
      if (cry[i] == ' ') {
        printf(" ");
      } else {
        printf("%c", temp[cry[i] - 'A']);
      }
    }
    printf("\n");
  }
}