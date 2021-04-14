#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  int n, num;
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d", &num);
    if (num == 0) {
      if (pq.empty()) {
        printf("0\n");
      } else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    } else {
      pq.push(num);
    }
  }
}