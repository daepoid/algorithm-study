#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  list<int> ls;
  for (int i = 0; i < 10; i++) {
    ls.push_back(i);
  }
  printf("%d\n", ls[ls.begin() + 3]);
}