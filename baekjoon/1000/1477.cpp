//
// Created by SeHyun on 2023-01-14.
//


#include "bits/stdc++.h"

using namespace std;

int N, M, L;
vector<int> v;

int main() {
    scanf("%d %d %d", &N, &M, &L);
    v.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int low = 1;
    int high = M - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        int now = 0;
        for (int i = 0; i < v.size(); i++) {
            int dist = v[i] - now;
            if (dist <= mid) {
                
            } else {

            }
        }
    }
}