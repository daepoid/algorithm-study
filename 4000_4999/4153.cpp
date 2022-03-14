#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  while(true){
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    if(a[0] == 0 && a[1] == 0 && a[2] == 0){
      break;
    }
    sort(a, a + 3);
    if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]){
      printf("right\n");
    }else{
      printf("wrong\n");
    }
  }
}