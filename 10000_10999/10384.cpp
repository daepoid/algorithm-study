#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int arr[26];
int main() {
  int n;
  string str;
  scanf("%d", &n);
  getline(cin, str);
  for(int j = 1; j <= n; j++){
    memset(arr, 0, sizeof(arr));
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
      if(isalpha(str[i])){
        arr[tolower(str[i]) - 'a']++;
      }
    }
    sort(arr, arr + 26);
    if(arr[0] == 0){
      printf("Case %d: Not a pangram\n", j);
    }else if(arr[0] == 1){
      printf("Case %d: Pangram!\n", j);
    }else if(arr[0] == 2){
      printf("Case %d: Double pangram!!\n", j);
    }else{
      printf("Case %d: Triple pangram!!!\n", j);
    }  
  }
}