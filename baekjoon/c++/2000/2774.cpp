#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

bool num[10];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int cnt = 0;
    char temp[20];
    memset(num, false, sizeof(num));
    scanf("%s", temp);
    for (int i = 0; temp[i] != '\0'; i++) {
      if (!num[temp[i] - '0']) {
        num[temp[i] - '0'] = true;
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}