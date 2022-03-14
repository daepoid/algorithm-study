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

int main() {
  int n;
  char A[7], B[7], C[7];
  strcpy(A, "ABC");
  strcpy(B, "BABC");
  strcpy(C, "CCAABB");
  string str;
  vector<pair<int, string>> student;
  student.push_back(make_pair(0, "Adrian"));
  student.push_back(make_pair(0, "Bruno"));
  student.push_back(make_pair(0, "Goran"));
  scanf("%d", &n);
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == A[i % 3]) {
      student[0].first++;
    }
    if (str[i] == B[i % 4]) {
      student[1].first++;
    }
    if (str[i] == C[i % 6]) {
      student[2].first++;
    }
  }
  int ans = max(student[0].first, max(student[1].first, student[2].first));
  printf("%d\n", ans);
  for (int i = 0; i < 3; i++) {
    if (student[i].first == ans) {
      cout << student[i].second << "\n";
    }
  }
}