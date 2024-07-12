#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long int n;
int ans[1000], i;

int main(){  
  scanf("%lld", &n);
  for(i = 0; n > 0; i++){
    ans[i] = n % 2;
    n /= 2;
  }
  for (int j = i - 1; j >= 0; j--) {
    if(j == i - 1 && ans[j] == 0){
      
    }else{
      printf("%d", ans[j]); 
    }
  }
  printf("\n");
}