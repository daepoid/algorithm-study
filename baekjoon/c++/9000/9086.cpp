#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    string str;
    cin >> str;
    cout << str[0] << str[str.length() - 1] << endl;
  }
}