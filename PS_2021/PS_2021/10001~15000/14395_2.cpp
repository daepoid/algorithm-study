#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll s, t;
string answer = "";
bool hasanswer = false;
set<ll> visited;
string oparr[4] = {"*", "+", "-", "/"};

void bfs() {
  queue<pair<ll, string>> q;
  q.push(make_pair(s, ""));
  visited.insert(s);

  while (!q.empty()) {
    ll num = q.front().first;
    string ops = q.front().second;
    q.pop();
    if (num == t) {
      answer = ops;
      hasanswer = true;
      return;
    }

    for (int i = 0; i < 4; i++) {
      ll newnum;
      if (i == 0) {
        newnum = num * num;
      } else if (i == 1) {
        newnum = num + num;
      } else if (i == 2) {
        newnum = num - num;
      } else if (i == 3) {
        if (num != 0) {
          newnum = num / num;
        }
      }

      if (newnum < 1) {
        continue;
      } else if (visited.find(newnum) != visited.end()) {
        continue;
      }
      visited.insert(newnum);
      q.push(make_pair(newnum, ops + oparr[i]));
    }
  }
}

int main() {
  scanf("%lld %lld", &s, &t);
  if (s == t) {
    printf("0\n");
    return 0;
  }
  bfs();
  if (hasanswer) {
    cout << answer << "\n";
  } else {
    printf("-1\n");
  }
}