#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int tc;

int main() {
  scanf("%d", &tc);
  while(tc-- > 0){
    string str, temp;
    cin >> str;
    temp = str.substr(0, str.length());
    reverse(str.begin(), str.end());
    int num = stoi(str) + stoi(temp);
    str = to_string(num);
    temp = str.substr(0, str.length());
    reverse(str.begin(), str.end());
    if(str == temp){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}