#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int by, int to){
  vector<int> temp;
  if(n == 1){
    temp.push_back(from);
    temp.push_back(to);
    answer.push_back(temp);
  }
  else{
    hanoi(n - 1, from, to, by);
    temp.push_back(from);
    temp.push_back(to);
    answer.push_back(temp);
    hanoi(n - 1, by, from, to);
  }
}

vector<vector<int>> solution(int n) {
  hanoi(n, 1, 2, 3);
  return answer;
}

int main () {
    int n = 2;
    vector<vector<int>> result = solution(n);
    for(vector<int> r : result) {
        cout << r[0] << " " << r[1] << "\n";
    }
}