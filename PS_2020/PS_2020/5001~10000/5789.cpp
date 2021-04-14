#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  char str[1001];
  while (tc-- > 0) {
    scanf("%s", str);
    if(str[strlen(str) / 2 - 1] == str[strlen(str) / 2]){
      printf("Do-it\n");
    }else{
      printf("Do-it-Not\n");
    }
  }
}