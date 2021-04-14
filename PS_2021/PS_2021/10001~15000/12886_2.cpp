#include <bits/stdc++.h>
using namespace std;

int answer = 0;
set<pair<pair<int, int>, int>> visited;

void bfs(int a, int b, int c) {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(a, b), c));
  visited.insert(make_pair(make_pair(a, b), c));

  while (!q.empty()) {
    a = q.front().first.first;
    b = q.front().first.second;
    c = q.front().second;
    q.pop();
    if (a == b && b == c) {
      answer = 1;
      return;
    }
    int newa, newb, newc;
    if (a != b) {
      newa = a < b ? a + a : a - b;
      newb = a < b ? b - a : b + b;
      newc = c;
      if (visited.find(make_pair(make_pair(newa, newb), newc)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(newa, newb), newc));
        q.push(make_pair(make_pair(newa, newb), newc));
      }
    }
    if (a != c) {
      newa = a < c ? a * 2 : a - c;
      newc = a < c ? c - a : c * 2;
      newb = b;
      if (visited.find(make_pair(make_pair(newa, newb), newc)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(newa, newb), newc));
        q.push(make_pair(make_pair(newa, newb), newc));
      }
    }
    if (b != c) {
      newb = b < c ? b * 2 : b - c;
      newc = b < c ? c - b : c * 2;
      newa = a;
      if (visited.find(make_pair(make_pair(newa, newb), newc)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(newa, newb), newc));
        q.push(make_pair(make_pair(newa, newb), newc));
      }
    }
  }
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  bfs(a, b, c);
  printf("%d\n", answer);
}