#include<bits/stdc++.h>
#define MAX 11
#define BASE 5
using namespace std;

int visited[MAX][MAX];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int get_dir(char ch) {
    switch(ch) {
        case 'R' : return 0;
        case 'D' : return 1;
        case 'L' : return 2;
        case 'U' : return 3;
        default: return 4;
    }
}

bool is_valid(int newy, int newx) {
    return 0 <= newy && newy < MAX && 0 <= newx && newx < MAX;    
}

int solution(string dirs) {
    int y = BASE;
    int x = BASE;
    int answer = 0;
    
    for(int i = 0; i < dirs.length(); i++) {
        int dir = get_dir(dirs[i]);
        int newy = y + dy[dir];
        int newx = x + dx[dir];
        
        if(!is_valid(newy, newx)) {
            continue;
        }
        
        if(!(visited[y][x] & (1 << dir))) {
            visited[y][x] |= (1 << dir);
            visited[newy][newx] |= (1 << ((dir + 2) % 4));
            answer++;     
        }
    
        y = newy;
        x = newx;    
    }
    
    return answer;
}