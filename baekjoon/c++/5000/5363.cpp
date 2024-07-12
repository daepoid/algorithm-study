#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int tc;

int main(){
  string str;
  scanf("%d", &tc);
  getline(cin, str);
  while(tc-- > 0){
    getline(cin, str);
    string ans;
    int check = 0;
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ' '){
        check++;
      }
      if(check == 2){
        ans = str.substr(i + 1);
        ans += " " + str.substr(0, i);
        break;
      }
    }
    cout << ans << "\n";
  }
}