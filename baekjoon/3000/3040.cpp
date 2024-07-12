#include<iostream>
#include<algorithm>
using namespace std;


int main() {
  int sum = 0;
  int i, j;
  int arr[10];
  for (i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  sum -= 100;
  for (i = 0; i < 9; i++) {
    for (j = i + 1; j < 9; j++) {
      if (arr[i] + arr[j] == sum) {
        for (int k = 0; k < 9; k++) {
          if (k != i && k != j) {
            printf("%d\n", arr[k]);
          }
        }
        return 0;
      }
    }
  }
  
}