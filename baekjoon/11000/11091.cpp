#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {
  int n;
  bool arr[26];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string str;
    bool flag = true;
    do {
      getline(cin, str);
    } while (str.length() == 0);
    memset(arr, false, 26);
    for (int j = 0; j < str.length(); j++) {
      if (isalpha(str[j])) {
        arr[tolower(str[j]) - 'a'] = true;        
      }
    }
    for (int j = 0; j < 26; j++) {
      if (!arr[j]) {
        if (flag) {
          printf("missing ");
          flag = false;
        }
        printf("%c", 'a' + j);
      }
    }
    if (flag) {
      printf("pangram\n");
    } else {
      printf("\n");
    }
  }
}