#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B){
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 0, j = A.size() - 1; i < A.size(); i++, j--){
        answer += (A[i] * B[j]);
    }   
    return answer;
}

int main () {
    vector<int> A = {1, 4, 2};
    vector<int> B = {5, 4, 4};
    int result = solution(A, B);
    cout << result << "\n";
}