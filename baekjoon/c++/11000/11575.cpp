#include<iostream>
using namespace std;

int a, b;
char str[10000001];

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc-- > 0) {
    scanf("%d %d", &a, &b);
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
      str[i] = ((str[i] - 'A') * a + b) % 26 + 'A';
    }  
    printf("%s\n", str);
  }
}