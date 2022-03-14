#include<iostream>
using namespace std;

int main() {
  char str[10];

  for (int i = 0; i < 3; i++) {
    scanf("%s", str);
    int cnt = 1, max = 1;
    for (int j = 0; j < 8; j++) {
      if (str[j] == str[j + 1]) {
        cnt++;
        if (cnt > max) {
          max = cnt;
        }
      } else {
        cnt = 1;
      }
    }
    printf("%d\n", max);
  }
}