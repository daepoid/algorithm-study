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

vector<int> graph[20001];
bool visited[20001];

int main() {
  int k, v, e, a, b;
  scanf("%d", &k);
  while (k-- > 0) {
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
      scanf("%d %d", &a, &b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
  }
}