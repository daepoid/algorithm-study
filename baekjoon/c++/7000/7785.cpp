#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){

  int tc;
  set<string> sets;
  scanf("%d", &tc);
  while(tc-- > 0){
    string a, b;
    cin >> a >> b;
    if(b.compare("enter") == 0){
      sets.insert(a);
    }else if(b.compare("leave") == 0){
      sets.erase(a);
    }
  }
  for (auto it = sets.rbegin(); it != sets.rend(); it++) {
    cout << *it << '\n';
  }
}