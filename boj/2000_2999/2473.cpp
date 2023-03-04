//
// Created by SeHyun on 2023-03-02.
//


#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX 5001
#define ll long long
using namespace std;

int N;
ll ans_a, ans_b, ans_c, answer = 3000000001;
ll arr[MAX];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    sort(arr, arr + N);

    for (int i = 0; i < N - 2; i++) {
        int low = i + 1;
        int high = N - 1;

        while (low < high) {
            ll sum = arr[i] + arr[low] + arr[high];

            if (abs(sum) < answer) {
                answer = abs(sum);
                ans_a = arr[i];
                ans_b = arr[low];
                ans_c = arr[high];
            }

            if (sum < 0) {
                low++;
            } else {
                high--;
            }
        }
    }
    printf("%lld %lld %lld", ans_a, ans_b, ans_c);
}