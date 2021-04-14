#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll s, t;
set<ll> visited;
int oplen = 31;
vector<string> opv;

void bfs() {
  queue<pair<ll, string>> q;
  q.push(make_pair(s, ""));
  visited.insert(s);

  while (!q.empty()) {
    ll num = q.front().first;
    string ops = q.front().second;
    q.pop();

    if (ops.length() > oplen) {
      continue;
    } else if (num == t) {
      oplen = ops.length();
      opv.push_back(ops);
    }

    for (int i = 0; i < 4; i++) {
      ll newnum = num;
      string newops = ops;
      if (i == 0) {
        newnum = num * num;
        newops += "*";
      } else if (i == 1) {
        newnum = num * 2;
        newops += "+";
      } else if (i == 2) {
        newnum = 0;
        newops += "-";
      } else if (i == 3) {
        if (num != 0) {
          newnum = 1;
          newops += "/";
        } else {
          continue;
        }
      }
      if (visited.find(newnum) == visited.end() && newnum <= t) {
        q.push(make_pair(newnum, newops));
      }
    }
  }
}

int main() {
  scanf("%lld %lld", &s, &t);
  ll temp = t;
  bool biflag = true;
  while (temp > 1) {
    if (temp % 2 != 0) {
      biflag = false;
      break;
    }
    temp /= 2;
  }

  if (t == s) {
    printf("0\n");
    return 0;
  } else if (t % s != 0 && !biflag) {
    printf("-1\n");
    return 0;
  }

  bfs();
  sort(opv.begin(), opv.end());
  cout << opv[0] << "\n";
}