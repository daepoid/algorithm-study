#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string a, b;

int main()
{
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string ans = to_string(atoi(a.c_str()) + atoi(b.c_str()));
  reverse(ans.begin(), ans.end());
  cout << atoi(ans.c_str()) << endl;
}