#include <bits/stdc++.h>
using namespace std;

typedef struct {
  string A = "";
  string B = "";
  string C = "";
} state;

state hanoi;
set<pair<pair<string, string>, string>> visited;

bool isclear(string a, string b, string c) {
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != 'A') {
      return false;
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] != 'B') {
      return false;
    }
  }
  for (int i = 0; i < c.length(); i++) {
    if (c[i] != 'C') {
      return false;
    }
  }
  return true;
}

void bfs() {
  queue<pair<state, int>> q;
  q.push(make_pair(hanoi, 0));
  visited.insert(make_pair(make_pair(hanoi.A, hanoi.B), hanoi.C));

  while (!q.empty()) {
    string a = q.front().first.A;
    string b = q.front().first.B;
    string c = q.front().first.C;
    int cnt = q.front().second;
    q.pop();

    if (isclear(a, b, c)) {
      printf("%d\n", cnt);
      return;
    }

    if (a.length() > 0) {
      string atemp = a.substr(0, a.length() - 1);
      string btemp = b + a[a.length() - 1];
      string ctemp = c + a[a.length() - 1];

      if (visited.find(make_pair(make_pair(atemp, btemp), c)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(atemp, btemp), c));
        state statetemp = {atemp, btemp, c};
        q.push(make_pair(statetemp, cnt + 1));
      }
      if (visited.find(make_pair(make_pair(atemp, b), ctemp)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(atemp, b), ctemp));
        state statetemp = {atemp, b, ctemp};
        q.push(make_pair(statetemp, cnt + 1));
      }
    }
    if (b.length() > 0) {
      string btemp = b.substr(0, b.length() - 1);
      string atemp = a + b[b.length() - 1];
      string ctemp = c + b[b.length() - 1];

      if (visited.find(make_pair(make_pair(atemp, btemp), c)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(atemp, btemp), c));
        state statetemp = {atemp, btemp, c};
        q.push(make_pair(statetemp, cnt + 1));
      }
      if (visited.find(make_pair(make_pair(a, btemp), ctemp)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(a, btemp), ctemp));
        state statetemp = {a, btemp, ctemp};
        q.push(make_pair(statetemp, cnt + 1));
      }
    }

    if (c.length() > 0) {
      string ctemp = c.substr(0, c.length() - 1);
      string atemp = a + c[c.length() - 1];
      string btemp = b + c[c.length() - 1];

      if (visited.find(make_pair(make_pair(atemp, b), ctemp)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(atemp, b), ctemp));
        state statetemp = {atemp, b, ctemp};
        q.push(make_pair(statetemp, cnt + 1));
      }
      if (visited.find(make_pair(make_pair(a, btemp), ctemp)) ==
          visited.end()) {
        visited.insert(make_pair(make_pair(a, btemp), ctemp));
        state statetemp = {a, btemp, ctemp};
        q.push(make_pair(statetemp, cnt + 1));
      }
    }
  }
}

int main() {
  string a, b, c;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int temp;
  cin >> temp;
  if (temp != 0) {
    cin >> hanoi.A;
  }
  cin >> temp;
  if (temp != 0) {
    cin >> hanoi.B;
  }
  cin >> temp;
  if (temp != 0) {
    cin >> hanoi.C;
  }
  bfs();
}