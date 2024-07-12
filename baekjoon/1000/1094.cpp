//
// Created by 박세현 on 2023/05/11.
//

#include "bits/stdc++.h"

using namespace std;

int X;

int main() {
    scanf("%d", &X);
    int answer = 1;
    while (X != 1) {
        if (X & 1) {
            answer++;
        }
        X /= 2;
    }
    printf("%d\n", answer);
}