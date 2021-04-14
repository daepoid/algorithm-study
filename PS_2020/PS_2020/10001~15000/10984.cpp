#include<iostream>
using namespace std;


int main() {
  int t, n;
  scanf("%d", &t);
  while (t-- > 0) {
    int total = 0;
    float gpa = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int temp1;
      float temp2;
      scanf("%d %f", &temp1, &temp2);
      total += temp1;
      gpa += temp1 * temp2;
    }
    cout << fixed;
    cout.precision(1);
    cout << total << " " << gpa / total << endl;
  }
}