#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  char *result;
  int ans = 0;
  char str[110];
  scanf("%s", str);
  
  result = strtok(str, ",");
  while (result != NULL) {
    ans++;
    result = strtok(NULL, ",");
  }
  printf("%d\n", ans);
}