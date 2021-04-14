#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc-- > 0) {
    string str;
    string ans = "";
    do {
      getline(cin, str);
    } while (str.length() == 0);
    
    for(int i = 0, j = 0; i < str.length(); i = j + 1){
      int cnt = 1;
      for(j = i + 1; str[j] != ' ' && str[j] != '\0'; j++){
        cnt++;
      }
      string temp = str.substr(i, cnt);
      reverse(temp.begin(), temp.end());
      ans += temp;
      if(str[j] != '\0'){
        ans += " ";
      }
    }
    cout << ans << endl;
  }
}