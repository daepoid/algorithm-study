#include<iostream>
using namespace std;

int main(){
  
  int n, tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    scanf("%d", &n);
    printf("Pairs for %d: ", n);
    for(int i = 1, j = n - i; i < j; i++, j--){
      printf("%d %d", i, j);
      if(i + 1 < j - 1){
        printf(", ");
      }
    }
    printf("\n");
  }
}