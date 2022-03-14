#include<iostream>
#include<cstring>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){

  char str[32];
  scanf("%s", str);
  while(str[0] != '#'){
    int cnt = 0;
    for(int i = 0; i < strlen(str) - 1; i++){
      if(str[i] == '1'){
        cnt++;
      }
    }
    if(str[strlen(str) - 1] == 'e'){
      if(cnt % 2 == 0){
        str[strlen(str) - 1] = '0';
      }else{
        str[strlen(str) - 1] = '1';
      }
    }else if(str[strlen(str) - 1] == 'o'){
      if(cnt % 2 == 0){
        str[strlen(str) - 1] = '1';
      }else{
        str[strlen(str) - 1] = '0';
      }
    }
    printf("%s\n", str);
    scanf("%s", str);
  }
}