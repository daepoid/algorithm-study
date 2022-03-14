#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int arr[5], temp;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        for (int k = 0; k < 5; k++) {
          if (k == 4) {
            printf("%d\n", arr[k]);
          } else {
            printf("%d ", arr[k]);
          }
        }
      }
    }
  }
}