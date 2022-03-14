#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n = 1;
  char jun[1001], kang[1001];
  scanf("%s", jun);
  scanf("%s", kang);
  while (strcmp(jun, "END") != 0 && strcmp(kang, "END") != 0) {
    if (strlen(jun) == strlen(kang)) {
      sort(jun, jun + strlen(jun));
      sort(kang, kang + strlen(kang));
      if (strcmp(jun, kang) == 0) {
        printf("Case %d: same\n", n); 
      } else {
        printf("Case %d: different\n", n); 
      }
    } else {
      printf("Case %d: different\n", n);
    }

    scanf("%s", jun);
    scanf("%s", kang);
    n++;
  }

}