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
#define MAX 1001
using namespace std;

bool visited[1001][1001];
int disp, clip, time, s;

int bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(1, 0), 0));
  visited[1][0] = true;
  while (!q.empty()) {
    disp = q.front().first.first;
    clip = q.front().first.second;
    time = q.front().second;
    q.pop();
    if (disp == s) {
      return time;
    }
    if (0 < disp && disp < MAX) {
      if (!visited[disp][disp]) {
        visited[disp][disp] = true;
        q.push(make_pair(make_pair(disp, disp), time + 1));
      }
      if (0 < clip && disp + clip < MAX) {
        if (!visited[disp + clip][clip]) {
          visited[disp + clip][clip] = true;
          q.push(make_pair(make_pair(disp + clip, clip), time + 1));
        }
      }
      if (!visited[disp - 1][clip]) {
        visited[disp - 1][clip] = true;
        q.push(make_pair(make_pair(disp - 1, clip), time + 1));
      }
    }
  }
}

int main() {
  scanf("%d", &s);
  printf("%d\n", bfs());
}