#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {

  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    int n, a = 0, b = 0;
    scanf("%d", &n);
    string str;
    for (int i = 0; i < n; i++) {
      do {
        getline(cin, str);
      } while (strlen(str.c_str()) != 3);
      if (str[0] == 'R') {
        if (str[2] == 'S') {
          a++;
        } else if (str[2] == 'P') {
          b++;
        } 
      } else if (str[0] == 'S') {
        if (str[2] == 'R') {
          b++;
        } else if (str[2] == 'P') {
          a++;
        } 
      } else if (str[0] == 'P') {
        if (str[2] == 'R') {
          a++;
        } else if (str[2] == 'S') {
          b++;
        } 
      }
    }
    if (a == b) {
      printf("TIE\n");
    } else if (a > b) {
      printf("Player 1\n");
    } else if (a < b) {
      printf("Player 2\n");
    }
  }
}