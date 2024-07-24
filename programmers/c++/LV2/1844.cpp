#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
bool visited[MAX][MAX];

bool is_valid(int newy, int newx, int N, int M) {
    return 0 <= newy && newy < N && 0 <= newx && newx < M;
}

int bfs(vector<vector<int> > maps) {
    visited[0][0] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    
    int N = maps.size();
    int M = maps[0].size();
    
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(y == N - 1 && x == M - 1) {
            return cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];
            
            if(!is_valid(newy, newx, N, M)) {
                continue;
            }
            
            if(visited[newy][newx]) {
                continue;
            }
            
            if(maps[newy][newx] == 0) {
                continue;
            }
            
            visited[newy][newx] = true;
            q.push({{newy, newx}, cnt + 1});
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps) {
    return bfs(maps);
}

int main() {
    vector<vector<int>> maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    int result = solution(maps);
    printf("%d\n", result);
}