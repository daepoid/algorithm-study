#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++) {
        ll temp = numbers[i];
        temp += ((temp ^ (temp + 1L)) >> 2) + 1L;
        answer.push_back(temp);
    }
    return answer;
}