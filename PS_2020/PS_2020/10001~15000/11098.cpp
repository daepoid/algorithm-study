#include<iostream>
#include<cstring>
using namespace std;

int main() {
  int tc, number_of_player;
  long long int player_price = 0, temp_price = 0;
  char player_name[21], temp_name[21];
  scanf("%d", &tc);
  while (tc-- > 0) {
    scanf("%d", &number_of_player);
    for (int i = 0; i < number_of_player; i++) {
      scanf("%lld %s", &temp_price, temp_name);
      if (temp_price > player_price) {
        player_price = temp_price;
        strcpy(player_name, temp_name);
      }
    }    
    printf("%s\n", player_name);
    player_price = 0;
  }
}