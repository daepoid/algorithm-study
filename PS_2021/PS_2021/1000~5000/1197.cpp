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

struct node {
  int my;
  int your;
  int weight;
};

int main() {
  int v, e;
  scanf("%d %d", &v, &e);
  for (int i = 0; i < e; i++) {
    node temp_node;
    scanf("%d %d %d", &temp_node.my, &temp_node.your, &temp_node.weight);
  }
}