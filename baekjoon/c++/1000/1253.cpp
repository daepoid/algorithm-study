//
// Created by SeHyun on 2023-01-13.
//


#include "bits/stdc++.h"

#define MAX 2001
using namespace std;

int N, answer = 0;
vector<int> v;

int main() {
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        int low = 0, high = N - 1;
        int val = v[i];
        while (low < high) {
            if (low == i) {
                low++;
            } else if (high == i) {
                high--;
            } else {
                if (v[low] + v[high] == val) {
                    answer++;
                    break;
                } else if (v[low] + v[high] < val) {
                    low++;
                } else if (v[low] + v[high] > val) {
                    high--;
                }
            }
        }
    }
    printf("%d\n", answer);
}