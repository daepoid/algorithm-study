//
// Created by 박세현 on 2023/04/04.
//

#include "bits/stdc++.h"

using namespace std;

int N;
pair<int, int> times[3];
int points[3];

int main() {
    scanf("%d", &N);

    int num, th, tm;
    int bf_h = 0, bf_m = 0;
    bool flags[3];
    for (int i = 0; i < N; i++) {
        scanf("%d %d:%d", &num, &th, &tm);
        points[num]++;

        if (i == 0) {
            bf_h = th;
            bf_m = tm;
            flags[num] = true;
            continue;
        }

        if (abs(points[1] - points[2]) == 0) {
            int temp = num == 1 ? 2 : 1;
            times[temp].first += (th - bf_h);
            times[temp].second += (tm - bf_m);
            flags[1] = false;
            flags[2] = false;
        } else if (abs(points[1] - points[2]) == 1) {
            int temp = num == 1 ? 2 : 1;
            if (!flags[temp]) {
                flags[num] = true;
                bf_h = th;
                bf_m = tm;
            }
        }
    }

    if (flags[1]) {
        times[1].first += (48 - bf_h);
        times[1].second += (00 - bf_m);
    } else if (flags[2]) {
        times[2].first += (48 - bf_h);
        times[2].second += (00 - bf_m);
    }

    for (int i = 1; i <= 2; i++) {
        while (times[i].second < 0 || 60 <= times[i].second) {
            if (times[i].second < 0) {
                times[i].first -= 1;
                times[i].second += 60;
            } else {
                times[i].first += 1;
                times[i].second -= 60;
            }
        }
    }

    printf("%02d:%02d\n", times[1].first, times[1].second);
    printf("%02d:%02d\n", times[2].first, times[2].second);
}