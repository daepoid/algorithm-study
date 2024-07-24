#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int solution(vector<vector<int> > land){
    int size = land.size() - 1;
    for(int i = 0 ; i < size; i++){
        land[i + 1][0] += max(land[i][1], land[i][2], land[i][3]);
        land[i + 1][1] += max(land[i][0], land[i][2], land[i][3]);
        land[i + 1][2] += max(land[i][0], land[i][1], land[i][3]);
        land[i + 1][3] += max(land[i][0], land[i][1], land[i][2]);        
    }
    int temp1 = max(land[size][0], land[size][1]);
    int temp2 = max(land[size][2], land[size][3]);    
    return max(temp1, temp2);
}

int main () {
    vector<vector<int>> land = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    int result = solution(land);
    cout << result << "\n";
}