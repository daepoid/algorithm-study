//
// Created by 박세현 on 2023/04/03.
//


#include "bits/stdc++.h"

#define MAX 1001
#define ll long long
using namespace std;

int N, C;
map<ll, int> fre, odr;
vector<pair<int, ll> > v;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return odr[a.second] < odr[b.second];
    }
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        fre[temp]++;
        if (odr[temp] == 0) {
            odr[temp] = i + 1;
        }
    }

    for (auto num: fre) {
        v.push_back(make_pair(num.second, num.first));
    }
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].first; j++) {
            cout << v[i].second << " ";
        }
    }
}