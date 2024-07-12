#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, sum;
  while(true){
    scanf("%d", &n);
    if(n == 0){
      break;
    }
    while (true) {
      sum = 1;
      if (n / 10 == 0) {
        printf("%d\n", n);
        break;
      }else{
        printf("%d ", n);
      }
      while (n != 0) {
        sum *= (n % 10);
        n /= 10;
      }
      n = sum;
    }
  }  
}