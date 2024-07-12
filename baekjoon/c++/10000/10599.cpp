#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int a, b, c, d;
  while(true){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a == 0 && b == 0 && c == 0 && d == 0){
      break;
    }
    printf("%d %d\n", c - b, d - a);
  }
}