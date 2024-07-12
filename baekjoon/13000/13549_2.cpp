#include <bits/stdc++.h>
#define MAX 200022
using namespace std;

int arr[MAX];
int N, K;
int answer = 0;

void solutions() {
    queue<int> q;
    q.push(K);
    arr[K] = 1;

    while(!q.empty()) {
        int num = q.front();
        int next_num = num;
        q.pop();

        if(num == N) {
            printf("%d\n", arr[num] - 1);
            return;
        }


        if(num - 1 >= 0) {
            next_num = num - 1;
            if(arr[next_num] == 0 || arr[next_num] > arr[num] + 1) {
                q.push(next_num);
                arr[next_num] = arr[num] + 1;
            }
        }

        if(num + 1 <= MAX) {
            next_num = num + 1;
            if (arr[next_num] == 0 || arr[next_num] > arr[num] + 1) {
                q.push(next_num);
                arr[next_num] = arr[num] + 1;
            }
        }

        if(num % 2 == 0) {
            next_num = num / 2;
            if (arr[next_num] == 0 || arr[next_num] > arr[num]) {
                q.push(next_num);
                arr[next_num] = arr[num];
            }
        }        
    }
}

int main() {
    scanf("%d %d", &N, &K);
    solutions();
}