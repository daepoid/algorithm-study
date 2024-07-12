//
// Created by SeHyun on 2023-03-02.
//


#include "bits/stdc++.h"

#define MAX 100001
using namespace std;

int N;
int arr[MAX];
int answer = 2147483647;
pair<int, int> answer_pair;


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0;
    int high = N - 1;

    while (low < high) {
        int temp = arr[low] + arr[high];
        if (abs(temp) < answer) {
            answer = abs(temp);
            answer_pair = {arr[low], arr[high]};
        }

        if (temp < 0) {
            low++;
        } else if (temp > 0) {
            high--;
        } else {
            break;
        }
    }
    printf("%d %d", answer_pair.first, answer_pair.second);
}