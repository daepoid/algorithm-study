//
// Created by 박세현 on 2023/04/05.
//


#include "bits/stdc++.h"

#define MAX 1000001
using namespace std;

int N;
int arr[MAX], answer[MAX];
stack<int> s;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            answer[i] = -1;
        } else {
            answer[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", answer[i]);
    }
}