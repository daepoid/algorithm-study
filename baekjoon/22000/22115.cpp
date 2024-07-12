#include <bits/stdc++.h>
#define MAX 111
#define INF 987654321
using namespace std;

int N, K;
int C[MAX];
int answer = 0, sum = 0;

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }
  sort(C, C + N, greater<int>());
  for (int i = 0; i < N; i++) {
    if (sum + C[i] < K) {
      sum += C[i];
      answer++;
    } else if (sum + C[i] == K) {
      sum += C[i];
      answer++;
      break;
    }
  }

  if (sum != K) {
    printf("-1\n");
  } else {
    printf("%d\n", answer);
  }
}
