#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool flag = false;
    for(int i = 1; i < words.size(); i++){
        if(words[i - 1][words[i - 1].length() - 1] != words[i][0]){
            flag = true;
        }        
        for(int j = 0; j < i; j++){
            if(words[i].compare(words[j]) == 0){
                flag = true;
            }
        }    
        if(flag){
            answer.push_back((i % n) + 1);
            answer.push_back(i / n + 1);
            break;
        }        
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}