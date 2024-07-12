//
// Created by SeHyun on 2023-01-10.
//


#include "bits/stdc++.h"

using namespace std;

int N;
int two = 0, five = 0;

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++) {
        int temp = i;
        while (temp % 5 == 0) {
            temp /= 5;
            five++;
        }
        while (temp % 2 == 0) {
            temp /= 2;
            two++;
        }
    }
    printf("%d\n", min(two, five));
}