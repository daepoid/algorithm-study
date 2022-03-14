#include<iostream>
using namespace std;

int temp;
int ans[6] = {1, 1, 2, 2, 2, 8};

int main() {
  for (int i = 0; i < 6; i++) {
    scanf("%d", &temp);
    ans[i] = ans[i] - temp;
  }
  for (int i = 0; i < 5; i++) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[5]);
}