#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int gan[6] = {1, 2, 3, 3, 4, 10};
int sa[7] = {1, 2, 2, 2, 3, 5, 10};

int main(){
  int tc;
  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++){
    int temp;
    int sasum = 0, gansum = 0;
    for (int i = 0; i < 6; i++) {
      scanf("%d", &temp);
      gansum += temp * gan[i];
    }
    for (int i = 0; i < 7; i++) {
      scanf("%d", &temp);
      sasum += temp * sa[i];
    }
    if(gansum > sasum){
      printf("Battle %d: Good triumphs over Evil\n", i);
    }else if(gansum < sasum){
      printf("Battle %d: Evil eradicates all trace of Good\n", i);
    }else if (gansum == sasum){
      printf("Battle %d: No victor on this battle field\n", i);
    }
  }
}