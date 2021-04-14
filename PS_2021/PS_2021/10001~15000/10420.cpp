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

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
  int year;
  int month;
  int day;
};

int main() {
  int n;
  scanf("%d", &n);
  date dday;
  dday.year = 2014;
  dday.month = 4;
  dday.day = 2;
  dday.day += (n - 1);
  while (dday.day > days[dday.month - 1]) {
    dday.day -= days[dday.month - 1];
    dday.month++;
    if (dday.month > 12) {
      dday.month = 1;
      dday.year++;
      if (dday.year % 4 == 0 && dday.year % 100 != 0) {
        days[1] = 29;
      } else {
        days[1] = 28;
      }
    }
  }
  printf("%d-%02d-%02d\n", dday.year, dday.month, dday.day);
}