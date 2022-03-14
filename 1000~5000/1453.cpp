#include <iostream>
#include <cstring>
using namespace std;

bool seat[100];

int main()
{

  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    if (!seat[temp - 1])
    {
      seat[temp - 1] = true;
    }
    else
    {
      ans++;
    }
  }
  printf("%d\n", ans);
}