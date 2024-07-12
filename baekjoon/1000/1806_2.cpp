#include <bits/stdc++.h>
#define MAX 100011
using namespace std;

long long int arr[MAX];
int N, S;
int answer = MAX;

void solutions() {
    int i = 0;
    int j = 1;
    long long int val = arr[0];

    while(true) {

        if(i > N || j > N) {
            break;
        }

        if(val >= S) {
            answer = min(answer, j - i);
            val -= arr[i];
            i++;
        } else if(val < S) {
            val += arr[j];
            j++;
        }
    }
    if(answer == MAX) {
        answer = 0;
    }
    printf("%d\n", answer);
}

int main() {
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    solutions();
}