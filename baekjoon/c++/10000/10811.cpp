#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int arr[100];

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    arr[i] = i + 1;
  }
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    reverse(arr + a - 1, arr + b);
  }
  for(int i = 0; i < n; i++){
    printf("%d", arr[i]);
    if(i + 1 < n){
      printf(" ");
    }else{
      printf("\n"); 
    }
  }
}