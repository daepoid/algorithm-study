#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  while(str.compare("#") != 0){
    int sum = 0;
    for(int i = 0 ; i < str.length(); i++){
      if(isalpha(str[i])){
        sum += (str[i] - 'A' + 1) * (i + 1);
      }
    }
    printf("%d\n", sum);
    getline(cin, str);
  }
}
