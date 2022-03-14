#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int number[10];
    for (int i = 0; i < 10; i++) {
      scanf("%d", &number[i]);
    }
    sort(number, number + 10); 
    printf("%d\n", number[7]);
  }
}