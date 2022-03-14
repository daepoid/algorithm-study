#include<iostream>
using namespace std;

int main() {

  int hour, min, need;

  scanf("%d %d", &hour, &min);
  scanf("%d", &need);

  min += need;
  hour = (hour + min / 60) % 24;
  min %= 60;
  printf("%d %d", hour, min);
}