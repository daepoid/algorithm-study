#include <bits/stdc++.h>
using namespace std;

struct datas {
    int score;
    string arr[4];
};

datas strtok(string str) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            temp += str[i];
        } else if (str[i] == ' ') {
            if (temp != "and") {
                v.push_back(temp);
            }
            temp = "";
        }
    }
    if (temp != "and") {
        v.push_back(temp);
    }
    return {stoi(v[4]), v[0], v[1], v[2], v[3]};
}

bool comp(datas a, datas b) { return a.score < b.score; }

vector<int> solution(vector<string> info, vector<string> query) {
    int cnt, small_cnt;
    vector<int> answer;
    vector<datas> board, nq;

    for (int i = 0; i < info.size(); i++) {
        board.push_back(strtok(info[i]));
    }

    for (int i = 0; i < query.size(); i++) {
        nq.push_back(strtok(query[i]));
    }

    sort(board.begin(), board.end(), comp);

    for (int i = 0; i < nq.size(); i++) {
        cnt = 0;
        for (int j = 0; j < board.size(); j++) {
            if (board[j].score >= nq[i].score) {
                small_cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (nq[i].arr[k] == "-" || nq[i].arr[k] == board[j].arr[k]) {
                        small_cnt++;
                    }
                }
                if (small_cnt == 4) {
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    vector<string> info = {"java backend junior pizza 150",
                           "python frontend senior chicken 210",
                           "python frontend senior chicken 150",
                           "cpp backend senior pizza 260",
                           "java backend junior chicken 80",
                           "python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int> results = solution(info, query);
    for(int result : results) {
        printf("%d ", result);
    }
    printf("\n");
}