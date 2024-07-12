#include <algorithm>
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
  int tc;
  scanf("%d", &tc);
  char str[41];
  int arr[8];
  while(tc--> 0){
    scanf("%s", str);
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= 38; i++){
      if(str[i - 1] == 'T'){
        if(str[i] == 'T'){
          if(str[i + 1] == 'T'){
            arr[0]++;
          }else if(str[i + 1] == 'H'){
            arr[1]++;
          }
        }else if(str[i] == 'H'){
          if (str[i + 1] == 'T') {
            arr[2]++;
          }else if(str[i + 1] == 'H'){
            arr[3]++;
          }
        }
      }else if(str[i - 1] == 'H'){
        if (str[i] == 'T') {
          if (str[i + 1] == 'T') {
            arr[4]++;
          } else if (str[i + 1] == 'H') {
            arr[5]++;
          }
        } else if (str[i] == 'H') {
          if (str[i + 1] == 'T') {
            arr[6]++;
          } else if (str[i + 1] == 'H') {
            arr[7]++;
          }
        }
      }
    }
    for(int i = 0; i < 8; i++){
      printf("%d", arr[i]);
      if(i + 1 < 8){
        printf(" ");
      }else{
        printf("\n");
      }
    }
  }
}