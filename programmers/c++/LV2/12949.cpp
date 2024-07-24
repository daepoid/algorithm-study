#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        vector<int> temp_vec;
        for(int k = 0; k < arr2[0].size(); k++){
            int temp = 0;
            for(int j = 0; j < arr2.size(); j++){
                temp += arr1[i][j] * arr2[j][k];
            }
            temp_vec.push_back(temp);            
        }
        answer.push_back(temp_vec);
    }
    return answer;
}

int main () {
    vector<vector<int>> arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr2 = {{3, 3}, {3, 3}};
    vector<vector<int>> result = solution(arr1, arr2);
    for(vector<int> r : result) {
        for(int c: r) {
            cout << c << " ";
        }
        cout << "\n";
    }
}