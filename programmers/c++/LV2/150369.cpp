#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0, d = 0, p = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        ll cnt = 0;
        d -= deliveries[i];
        p -= pickups[i];
        
        while(d < 0 || p < 0) {
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
    }
    
    return answer;
}

int main() { 
    int cap = 4;
    int n = 5;
    vector<int> deliveries = {1, 0, 3, 1, 2};
    vector<int> pickups = {0, 3, 0, 4, 0};
    long long result = solution(cap, n, deliveries, pickups);
    printf("%lld\n", result);
}