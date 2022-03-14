#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  for(int i = 0; i < n; i++){
    int temp;
    int max = sqrt(w * w + h * h);
    scanf("%d", &temp);
    if(temp <= max){
      printf("DA\n");
    }else{
      printf("NE\n");
    }  
  }
}