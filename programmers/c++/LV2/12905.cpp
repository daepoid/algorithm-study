#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board){
    int answer = 0;
    
    if(board.size() < 2 || board[0].size() < 2){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 1){
                    return 1;
                }
            }
        }
    }
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] == 1){
                int min = board[i][j - 1] < board[i - 1][j - 1] ? board[i][j - 1] : board[i - 1][j - 1];
                min = min < board[i - 1][j] ? min : board[i - 1][j];
                board[i][j] = min + 1;
                if(board[i][j] > answer){
                    answer = board[i][j];
                }
            }
        }
    }    
    return answer * answer;
}

int main () {
    vector<vector<int>> board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
    int result = solution(board);
    cout << result << "\n";
}