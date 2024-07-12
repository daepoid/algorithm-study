#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  char str[12];
  int turn = 0, sum = 0;
  int before = 0;
  int flag = 0;
  while(true){
    scanf("%s", str);
    if(isdigit(str[0])){
      if(flag == 0){
        sum = stoi(str);
      }
      else if (flag == 1) {
        sum += stoi(str);
      } else if (flag == 2) {
        sum -= stoi(str);
      } else if (flag == 3) {
        sum *= stoi(str);
      } else if (flag == 4) {
        sum /= stoi(str);
      }
    }else{
      if (strcmp(str, "+") == 0) {
        flag = 1;
      } else if (strcmp(str, "-") == 0) {
        flag = 2;
      } else if (strcmp(str, "*") == 0) {
        flag = 3;
      } else if (strcmp(str, "/") == 0) {
        flag = 4;
      } else if (strcmp(str, "=") == 0) {
        break;
      }
    }
  }
  printf("%d\n", sum);
}