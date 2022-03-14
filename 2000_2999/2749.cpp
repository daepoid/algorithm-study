#include <bits/stdc++.h>
#define cycle 1500000
using namespace std;

long long int arr[1500011];
int mod = 1000000;

void fib() {
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 0; i < cycle; i++) {
    arr[i + 2] = (arr[i + 1] + arr[i]) % mod;
  }
}

int main() {
  long long int n;
  scanf("%lld", &n);
  fib();
  printf("%lld\n", arr[n % cycle]);
}