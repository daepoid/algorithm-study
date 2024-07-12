#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  vector<int> ans;
  int n, temp, count = 0;
  int arr[10];
  for(int i = 0; i < 10; i++){
    arr[i] = (i % 5) + 1;
  }
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    count = 0;
    for(int j = 0; j < 10; j++){
      scanf("%d", &temp);
      if (temp == arr[j]) {
        count++;
      }
    }
    if(count == 10){
      ans.push_back(i + 1);
    }
  }
  for(int i = 0; i < ans.size(); i++){
    printf("%d\n", ans[i]);
  }
}