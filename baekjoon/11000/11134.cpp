#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int tc, n, c;
  scanf("%d", &tc);
  while (tc-- > 0) {
    scanf("%d %d", &n, &c);
    if(n % c == 0){
      printf("%d\n", n / c);
    }else{
      printf("%d\n", n / c + 1);
    }
  }
}