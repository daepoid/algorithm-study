#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

bool isclear(vector<bool> isvisited) {
  for (int i = 0; i < isvisited.size(); i++) {
    if (!isvisited[i]) {
      return false;
    }
  }
  return true;
}

void bfs(int city_nodes, vector<int> city_from, vector<int> city_to,
         int company) {
  queue<int> q;
  vector<bool> isvisited(city_nodes + 1, false);
  q.push(company);

  while (!q.empty()) {
    int pos = q.front();
    arr.push_back(pos);
    q.pop();
    isvisited[pos] = true;
    if (isclear(isvisited)) {
      return;
    }
    while (true) {
      auto iter = find(city_from.begin(), city_from.end(), pos);
      if (iter == city_from.end()) {
        break;
      } else {
        int temp = city_to[iter - city_from.begin()];
        if (!isvisited[temp]) {
          q.push(temp);
        }
      }
    }
  }
}

vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to,
                  int company) {
  bfs(city_nodes, city_from, city_to, company);
  return arr;
}

int main() {
  vector<string> v;
  vector<long> a, b;
  vector<int> c;
  a.push_back(3);
  a.push_back(0);
  a.push_back(4);
  a.push_back(5);

  b.push_back(3);
  b.push_back(3);
  b.push_back(5);
  b.push_back(7);

  c.push_back(3);
  c.push_back(1);
  c.push_back(2);
  c.push_back(2);
  printf("%d\n", taxiDriver(a, b, c));
}