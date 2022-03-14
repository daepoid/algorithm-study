#include<iostream>
using namespace std;

int ans[3];

int main(){
  
  int h, m, s;
  for(int j = 0; j < 3; j++){
    scanf("%d %d %d", &h, &m, &s);
    scanf("%d %d %d", &ans[0], &ans[1], &ans[2]);
    ans[2] -= s;
    if(ans[2] < 0){
      ans[1]--;
      ans[2] += 60;
    }
    ans[1] -= m;
    if(ans[1] < 0){
      ans[0]--;
      ans[1] += 60;
    }
    ans[0] -= h;
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
  }
}