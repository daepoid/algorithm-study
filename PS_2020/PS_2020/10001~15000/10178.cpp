#include<iostream>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int candy, people;
    scanf("%d %d", &candy, &people);
    printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy / people, candy % people);
  }
}