#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int input[MAX];
int output[MAX];

bool isCreated(int idx) {
    return input[idx] == 0 && output[idx] >= 2;
}

bool isBar(int idx) {
    return output[idx] == 0;
}

bool is8(int idx) {
    return input[idx] >= 2 && output[idx] == 2;    
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    int maxNode = 0;
    for(auto edge: edges) {
        input[edge[1]]++;
        output[edge[0]]++;    
        maxNode = max(maxNode, max(edge[0], edge[1]));
    }
    
    for(int i = 1; i < maxNode + 1; i++) {
        if(isCreated(i)) {
            answer[0] = i;
        } else if(isBar(i)) {
            answer[2]++;
        } else if(is8(i)) {
            answer[3]++;
        }
    }
    
    answer[1] = output[answer[0]] - (answer[2] + answer[3]);
    return answer;
}

int main() {
    vector<vector<int>> edges = {{2, 3}, {4, 3}, {1, 1}, {2, 1}};
    vector<int> results = solution(edges);
    for(int result : results) {
        printf("%d ", result);
    }
    printf("\n");
}