#include <bits/stdc++.h>
using namespace std;

long long arr[21];

vector<int> solution(int n, long long k) {
  vector<int> answer, vec;
  long long Q, R = k - 1;
  arr[0] = 1;
  for(int i = 1; i < n + 1; i++){
    vec.push_back(i);
    arr[i] = arr[i - 1] * i;
  }
  for(int i = n - 1; i >= 0; i--){
    Q = R / arr[i];
    R = R % arr[i];
    answer.push_back(vec[Q]);
    vec.erase(vec.begin() + Q);
  }
  if(!vec.empty()){
    answer.push_back(vec[0]);
  }
  return answer;
}

int main () {
    int n = 3;
    long long k = 5;
    vector<int> result = solution(n, k);
    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }
}