#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n;
  int arr[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  if (n != 1) {
    printf("%d ", arr[0]);
  } else {
    printf("%d\n", arr[0]);
  }
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] != arr[i]) {
      printf("%d", arr[i]);
      if (i + 1 < n) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }
}