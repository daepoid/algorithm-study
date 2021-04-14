#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*
NOTE: mod 계산 수학적으로 이해하기
*/

int main() {
  long long int num, cnt, ans;
  while (scanf("%lld", &num) != EOF) {
    cnt = 1;
    ans = 1;
    while (1) {
      if (ans % num == 0) {
        printf("%lld\n", cnt);
        break;
      }
      ans = ans % num * 10 + 1;
      cnt++;
    }
  }
}