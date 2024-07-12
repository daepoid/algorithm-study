#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main(){

  int tc;
  scanf("%d", &tc);
  char a[101], b[101];
  while(tc-- > 0){
    int dist = 0;
    scanf("%s %s", a, b);
    for(int i = 0; i < strlen(a); i++){
      if(a[i] != b[i]){
        dist++;
      }
    }
    printf("Hamming distance is %d.\n", dist);
  }
}