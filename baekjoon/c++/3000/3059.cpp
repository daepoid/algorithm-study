#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main() {

  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    char str[1010];
    int sum = 0;
    bool check[26];
    memset(check, false, 26);
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
      if (!check[str[i] - 'A']) {
        check[str[i] - 'A'] = true;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (!check[i]) {
        sum += i + 65;
      }
    }
    printf("%d\n", sum);
  }
}