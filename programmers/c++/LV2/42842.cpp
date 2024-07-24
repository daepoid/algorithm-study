#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int total = brown + red;
    for(int i = 3; i <= sqrt(total); i++){
        if(total % i == 0){
            int j = total / i;
            if((i - 2) * (j - 2) == red){
                answer.push_back(j);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}