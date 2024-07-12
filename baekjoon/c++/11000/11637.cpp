#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc-- > 0){
    int n, num, sum = 0;
    vector<pair<int, int>> arr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &num);
      arr.push_back(make_pair(num, i + 1));
      sum += num;
    }
    sort(arr.begin(), arr.end());
    if (arr[n - 1].first == arr[n - 2].first) {
      printf("no winner\n");
    } else if (arr[n - 1].first > sum / 2){
      printf("majority winner %d\n", arr[n - 1].second);  
    }else if(arr[n - 2].first <= sum / 2){
      printf("minority winner %d\n", arr[n - 1].second);     
    }
  }
}