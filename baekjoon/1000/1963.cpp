#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int visited[10001], answer;
bool noprimes[10001];
void primeset() {

  for (int i = 2; i < 5000; i++) {
    for (int j = i * 2; j < 10000; j += i) {
      noprimes[j] = true;
    }
  }
}

void bfs(char start[], char end[], int masknum) {
  queue<pair<int, int>> q;
  int endnum = stoi(end);
  q.push(make_pair(stoi(start), 0));
  visited[stoi(start)] = masknum;
  if (strcmp(start, end) == 0) {
    answer = 0;
    return;
  }

  while (!q.empty()) {
    int num = q.front().first;
    int cnt = q.front().second;
    q.pop();
    if (num == endnum) {
      answer = min(answer, cnt);
    }

    string strnum = to_string(num);
    for (int i = 0; i < 4; i++) {
      string temp = strnum;
      for (int j = 0; j < 10; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        temp[i] = '0' + j;
        int tempnum = stoi(temp);
        if (temp == strnum) {
          continue;
        } else if (noprimes[tempnum]) {
          continue;
        } else if (visited[tempnum] == masknum) {
          continue;
        }
        visited[tempnum] = masknum;
        // printf("%d: %d\n", num, tempnum);
        q.push(make_pair(tempnum, cnt + 1));
      }
    }
  }
}

int main() {
  int tc;
  char start[5], end[5];
  scanf("%d", &tc);
  primeset();
  for (int i = 1; i < tc + 1; i++) {
    scanf("%s %s", start, end);
    answer = INF;
    bfs(start, end, i);
    if (answer == INF) {
      printf("Impossible\n");
    } else {
      printf("%d\n", answer);
    }
  }
}