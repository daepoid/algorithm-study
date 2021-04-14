#include<iostream>
using namespace std;

int main(){

  int n;
  char str[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    int j, a = 0, b = 0;
    if (str[0] == 'P') {
      printf("skipped\n");
    } else {
      for (j = 0; str[j] != '+'; j++) {
        a = a * 10 + (str[j] - '0');
      }
      for (j = j + 1; str[j] != '\0'; j++) {
        b = b * 10 + (str[j] - '0');
      }
      printf("%d\n", a + b);
    }    
  }
}