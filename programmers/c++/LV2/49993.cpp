#include <bits/stdc++.h>
using namespace std;

int skill_seq[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int last = 0;
    bool flag = false;
    for(int i = 0; i  < skill.length(); i++){
        skill_seq[skill[i] - 'A'] =  i + 1;
    }
    
    for(int i = 0; i < skill_trees.size(); i++){
        last = 0;
        flag = false;
        for(int j = 0; j < skill_trees[i].length(); j++){
            int temp = skill_seq[skill_trees[i][j] - 'A'];
            if(temp != 0){
                if(last + 1 == temp){
                    last++;
                }
                else if(last > temp || last + 1  < temp){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            answer++;
        }
    }
    return answer;
}