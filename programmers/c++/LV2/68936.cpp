#include<bits/stdc++.h>
using namespace std;

vector<int> answer(2, 0);

bool is_same_number(vector<vector<int>> &arr, int y, int x, int len) {
    int first = arr[y][x];
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++) {
            if(first != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void compact(vector<vector<int>> &arr, int y, int x, int len) {
    if(len == 1) {
        answer[arr[y][x]]++;
        return;
    }
    
    if(is_same_number(arr, y, x, len)) {
        answer[arr[y][x]]++;
        return ;
    }
    
    len /= 2;
    compact(arr, y, x, len);
    compact(arr, y, x + len, len);
    compact(arr, y + len, x, len);
    compact(arr, y + len, x + len, len);
}

vector<int> solution(vector<vector<int>> arr) {
    compact(arr, 0, 0, arr.size());
    return answer;
}