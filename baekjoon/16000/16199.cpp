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

struct date {
  int year;
  int month;
  int day;
};

int main() {
  date start, end;
  int temp;

  scanf("%d %d %d", &start.year, &start.month, &start.day);
  scanf("%d %d %d", &end.year, &end.month, &end.day);
  temp = start.month < end.month ||
                 (start.month == end.month && start.day <= end.day)
             ? 0
             : 1;
  printf("%d\n", end.year - start.year - temp);
  printf("%d\n", end.year - start.year + 1);
  printf("%d\n", end.year - start.year);
}