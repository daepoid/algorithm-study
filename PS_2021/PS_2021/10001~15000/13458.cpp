#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int n;
int arr[MAX];

int main() {
  int master, sub;
  long long int answer = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d %d", &master, &sub);
  for (int i = 0; i < n; i++) {
    answer++;
    arr[i] -= master;
    if (arr[i] > 0) {
      answer += (arr[i] - 1) / sub + 1;
    }
  }
  printf("%lld\n", answer);
}