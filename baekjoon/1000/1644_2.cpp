#include <bits/stdc++.h>
#define MAX 4000011
using namespace std;

int N, answer = 0;
bool notPrime[MAX];
vector<int> prime;

void primeInit() {
    for(int i = 2; i <= N; i++) {
        for(int j = 2; i * j <= N; j++) {
            notPrime[i * j] = true;
        }
    }
    for(int i = 2; i <= N; i++) {
        if(!notPrime[i]) {
            prime.push_back(i);
        }
    }
}

int cal(int left, int right) {
    int sum = 0;
    for (int i = left; i < right; i++) {
        sum += prime[i];
    }
    return sum;
}

void solutions() {

    int i = 0;
    int j = 1;
    while(true) {

        if(i > prime.size() || j > prime.size()) {
            break;
        }

        int val = cal(i, j);
        if (val < N) {
            j++;
        }
        else if (val > N) {
            i++;
        }
        else if (val == N) {
            answer++;
            i++;
        }
        
        if(i >= j) {
            break;
        }
    }
}

int main() {
    scanf("%d", &N);
    primeInit();
    solutions();
    printf("%d\n", answer);
}