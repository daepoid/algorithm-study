#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main() {
  time_t rawTime;
  struct tm* pTimeInfo;

  rawTime = time(NULL);
  pTimeInfo = localtime(&rawTime);
  int year = pTimeInfo->tm_year + 1900;
  int month = pTimeInfo->tm_mon + 1;
  int day = pTimeInfo->tm_mday;
  printf("%d\n%d\n%d\n", year, month, day);
  return 0;
}