#include <bits/stdc++.h>
using namespace std;

int arr1[1001], arr2[1001];

int main() {
  int t, n, m;
  long long int sum = 0, answer = 0;
  map<long long int, long long int> llm;
  scanf("%d", &t);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr1[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &arr2[i]);
  }

  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr1[j];
      llm[sum]++;
    }
  }

  for (int i = 0; i < m; i++) {
    sum = 0;
    for (int j = i; j < m; j++) {
      sum += arr2[j];
      answer += llm[t - sum];
    }
  }

  printf("%lld\n", answer);
}