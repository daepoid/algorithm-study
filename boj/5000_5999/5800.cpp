#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int j = 0; j < tc; j++) {
    int n, gap = 0;
    int score[51];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &score[i]);
    }
    sort(score, score + n);
    for (int i = 0; i < n - 1; i++) {
      if (gap < abs(score[i] - score[i + 1])) {
        gap = abs(score[i] - score[i + 1]);
      }
    }
    printf("Class %d\n", j + 1);
    printf("Max %d, Min %d, Largest gap %d\n", score[n - 1], score[0], gap);
  }
}