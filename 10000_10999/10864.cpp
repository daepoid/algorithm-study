#include<iostream>
using namespace std;

int n, m;
int ans[1001];

int main(){
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    ans[a]++;
    ans[b]++;
  }
  for(int i = 1; i <= n; i++){
    printf("%d\n", ans[i]);
  }
}