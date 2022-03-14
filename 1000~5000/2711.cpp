#include<iostream>
using namespace std;

int main() {

  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int n;
    char str[81];
    scanf("%d %s", &n, str);
    for (int i = n - 1; i < sizeof(str); i++) {
      str[i] = str[i + 1];
    }
    printf("%s\n", str);
  }
}