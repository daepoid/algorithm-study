#include <bits/stdc++.h>
using namespace std;

bool isprime[4000001];
vector<int> primes;

void check_prime(int num) {
  for (int i = 2; i < num + 1; i++) {
    if (!isprime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j < num + 1; j += i) {
        isprime[j] = true;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  check_prime(n);
  int sum = 0, low = 0, high = 0, cnt = 0;

  while (true) {
    if (sum >= n) {
      sum -= primes[low++];
    } else if (high == primes.size()) {
      break;
    } else {
      sum += primes[high++];
    }

    if (sum == n) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}