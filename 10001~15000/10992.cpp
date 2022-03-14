#include<iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (n - i <= j && j <= n + i) {
        if ((i != 0 && i != n - 1) && (n - i != j && n + i != j)) { 
          printf(" ");
        } else {
          printf("*"); 
        }
      } else if(j < n - i){
        printf(" ");
      }
    }
    printf("\n");
  }
}