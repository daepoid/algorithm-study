#include <bits/stdc++.h>
#define MAX 10011
using namespace std;

long long int arr[MAX];
int N, M;
int answer = 0;

void solutions() {
    int i = 0;
    int j = 1;
    long long int val = arr[0];

    while (true) {

        if (i > N || j > N) {
            break;
        }

        if (val < M) {
            val += arr[j];
            j++;
        }
        else {
            if(val == M) {
                answer++;
            }
            val -= arr[i];
            i++;
        }
    }

    printf("%d\n", answer);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    solutions();
}