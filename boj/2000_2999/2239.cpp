//
// Created by SeHyun on 2023-03-02.
//


#include "bits/stdc++.h"

#define MAX 9
using namespace std;

int board[MAX][MAX];

int main() {
    string str;
    for (int i = 0; i < MAX; i++) {
        cin >> str;
        for (int j = 0; j < MAX; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j] == 0) {

            }
        }
    }

    for (int i = 0; i < MAX; i++) {
        
    }

}