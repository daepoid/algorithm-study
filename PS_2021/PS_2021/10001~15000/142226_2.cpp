#include <bits/stdc++.h>
#define MAX 2222
using namespace std;

bool visited[MAX][MAX];
int S;

int bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(1, 0), 0));
  visited[1][0] = true;

  while (!q.empty()) {
    int cnt = q.front().first.first;
    int clip = q.front().first.second;
    int time = q.front().second;
    q.pop();

    if (cnt == S) {
      return time;
    }
    if (0 < cnt && cnt < MAX) {
      if (!visited[cnt][cnt]) {
        visited[cnt][cnt] = true;
        q.push(make_pair(make_pair(cnt, cnt), time + 1));
      }
      if (0 < clip && cnt + clip < MAX) {
        if (!visited[cnt + clip][clip]) {
          visited[cnt + clip][clip] = true;
          q.push(make_pair(make_pair(cnt + clip, clip), time + 1));
        }
      }
      if (!visited[cnt - 1][clip]) {
        visited[cnt - 1][clip] = true;
        q.push(make_pair(make_pair(cnt - 1, clip), time + 1));
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d", &S);
  printf("%d\n", bfs());
}