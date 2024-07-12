//
// Created by 박세현 on 2023/03/18.
//

#include "bits/stdc++.h"

#define MAX 1001
using namespace std;

int T, N;
int arr[MAX];

int main() {
    scanf("%d", &T);
    while(T-- > 0) {
        scanf("%d", &N);

        for(int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
    }
}