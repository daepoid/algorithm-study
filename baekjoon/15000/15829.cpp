//
// Created by SeHyun on 2023-01-09.
//


#include "bits/stdc++.h"

#define MOD 1234567891
#define R 31
using namespace std;

int L;

int hashing(string str) {
    long long int sum = 0;
    long long int r = 1;

    for (int i = 0; i < L; i++) {
        int val = str[i] - 'a' + 1;
        sum = (sum + (val * r)) % MOD;
        r = (r * R) % MOD;
    }
    return sum;
}

int main() {
    string str;
    cin >> L >> str;
    printf("%d\n", hashing(str));
}