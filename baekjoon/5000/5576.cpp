#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int w[10], k[10];
  for (int i = 0; i < 10; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < 10; i++) {
    scanf("%d", &k[i]);
  }
  sort(w, w + 10);
  sort(k, k + 10);
  printf("%d %d", w[7] + w[8]+ w[9], k[7] + k[8] + k[9]);
}