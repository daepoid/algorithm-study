#include<iostream>
using namespace std;

int main(){

  int tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    double d;
    scanf("%lf", &d);
    printf("$%.2lf\n", d * 0.8);
  }
}