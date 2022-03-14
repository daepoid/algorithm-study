#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main() {

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char str[21];
    scanf("%s", str);
    for (int j = 0; j < strlen(str); j++) {
      str[j] = tolower(str[j]);
    }
    printf("%s\n", str);
  }
}