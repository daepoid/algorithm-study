#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<pair<int, string>> v;
  v.push_back(pair<int, string>(1967, "DavidBowie"));
  v.push_back(pair<int, string>(1969, "SpaceOddity"));
  v.push_back(pair<int, string>(1970, "TheManWhoSoldTheWorld"));
  v.push_back(pair<int, string>(1971, "HunkyDory"));
  v.push_back(pair<int, string>(
      1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
  v.push_back(pair<int, string>(1973, "AladdinSane"));
  v.push_back(pair<int, string>(1973, "PinUps"));
  v.push_back(pair<int, string>(1974, "DiamondDogs"));
  v.push_back(pair<int, string>(1975, "YoungAmericans"));
  v.push_back(pair<int, string>(1976, "StationToStation"));
  v.push_back(pair<int, string>(1977, "Low"));
  v.push_back(pair<int, string>(1977, "Heroes"));
  v.push_back(pair<int, string>(1979, "Lodger"));
  v.push_back(pair<int, string>(1980, "ScaryMonstersAndSuperCreeps"));
  v.push_back(pair<int, string>(1983, "LetsDance"));
  v.push_back(pair<int, string>(1984, "Tonight"));
  v.push_back(pair<int, string>(1987, "NeverLetMeDown"));
  v.push_back(pair<int, string>(1993, "BlackTieWhiteNoise"));
  v.push_back(pair<int, string>(1995, "1.Outside"));
  v.push_back(pair<int, string>(1997, "Earthling"));
  v.push_back(pair<int, string>(1999, "Hours"));
  v.push_back(pair<int, string>(2002, "Heathen"));
  v.push_back(pair<int, string>(2003, "Reality"));
  v.push_back(pair<int, string>(2013, "TheNextDay"));
  v.push_back(pair<int, string>(2016, "BlackStar"));

  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int a, b, cnt = 0;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < v.size(); i++) {
      if (a <= v[i].first && v[i].first <= b) {
        cnt++;
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < v.size(); i++) {
      if (a <= v[i].first && v[i].first <= b) {
        cout << v[i].first << " " << v[i].second << endl;
      }
    }
  }
}