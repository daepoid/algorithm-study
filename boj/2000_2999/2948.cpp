#include<iostream>
using namespace std;

int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
string day[7] = {"Thursday",
                 "Friday",
                 "Saturday",
                 "Sunday",
                 "Monday",
                 "Tuesday",
                 "Wednesday"};

int main() {
  int d, m;
  scanf("%d %d", &d, &m);
  cout << day[(days[m - 1] + d - 1) % 7] << endl;
}