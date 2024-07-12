#include <iostream>
using namespace std;
int main(){
  int num = 1;
  while(true){
    int n;
    scanf("%d", &n);
    if(n == 0){
      break;
    }
    if(n % 2 == 0){
      printf("%d. even %d\n", num, n / 2);
    }else {
      printf("%d. odd %d\n", num, (n - 1) / 2);    
    }
    num++;
  }
}