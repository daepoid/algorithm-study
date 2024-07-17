#include <bits/stdc++.h>
#define MAX 501
#define MAX_DIR 4
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int N, M;
bool visited[MAX][MAX][MAX_DIR];

int next_dir(int dir, char ch) {
    switch (ch) {
        case 'L' : return (dir + 3) % MAX_DIR;
        case 'R' : return (dir + 1) % MAX_DIR;
        default: return dir;
    }
}

int simulation(int y, int x, int dir, int cnt, vector<string>& grid) {
    
    if(visited[y][x][dir]) return cnt;
    visited[y][x][dir] = true;
    
    int newd = next_dir(dir, grid[y][x]);
    int newy = (y + dy[newd] + N) % N;
    int newx = (x + dx[newd] + M) % M;
    return simulation(newy, newx, newd, cnt + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    N = grid.size();
    M = grid[0].length();
        
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                int result = simulation(i, j, k, 0, grid);
                if (result) {
                    answer.push_back(result);
                } 
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> grid = {"SL","LR"};
    vector<int> result = solution(grid);
    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}