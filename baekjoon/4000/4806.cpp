#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

long long int n;

int main() {
  string str;
  getline(cin, str);
  while(!cin.eof()){
    getline(cin, str);
    n++;
  }
  printf("%lld\n", n);
}