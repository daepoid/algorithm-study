#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {
  int a, b, i = 1;
  char str[5];
  while (true) {
    scanf("%d %s %d", &a, str, &b);
    if (strcmp (str, ">") == 0) {
      printf("Case %d: %s\n", i, a > b ? "true" : "false");
    } else if (strcmp(str, ">=") == 0) {
      printf("Case %d: %s\n", i, a >= b ? "true" : "false");
    } else if (strcmp(str, "<") == 0) {
      printf("Case %d: %s\n", i, a < b ? "true" : "false");
    } else if (strcmp(str, "<=") == 0) {
      printf("Case %d: %s\n", i, a <= b ? "true" : "false");
    } else if (strcmp(str, "==") == 0) {
      printf("Case %d: %s\n", i, a == b ? "true" : "false");
    } else if (strcmp(str, "!=") == 0) {
      printf("Case %d: %s\n", i, a != b ? "true" : "false");
    } else if (strcmp(str, "E") == 0) {
      return 0;
    }
    i++;
  }
}