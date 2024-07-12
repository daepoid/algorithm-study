#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  while(true){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 0 && b == 0 && c == 0){
      break;
    }
    if(b - a == c - b){
      printf("AP %d\n", c + b - a);
    }else{
      printf("GP %d\n", c * (b / a));
    }
  }
}