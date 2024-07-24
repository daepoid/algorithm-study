#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = 0; i < size; i++){
        if(citations[i] < i + 1){
            return i;
        }
    }
    return size;
}