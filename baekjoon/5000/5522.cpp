#include<iostream>
using namespace std;

int main() {

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int temp;
    scanf("%d", &temp);
    ans += temp;
  }
  printf("%d\n", ans);
}