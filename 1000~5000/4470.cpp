#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main() {

  int n;
  scanf("%d", &n);
  string str;
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    str = to_string(i + 1) + ". " + str;
    cout << str << endl;
  }
}