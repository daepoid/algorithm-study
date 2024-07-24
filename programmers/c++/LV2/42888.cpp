#include<bits/stdc++.h>
using namespace std;

vector<string> strtok(string record){
    vector<string> log;
    string temp = "";
    int len = record.length();
    for(int j = 0; j < len; j++){
        if(record[j] == ' '){
            log.push_back(temp);
            temp = "";
        }else{
            temp += record[j];
        }
    }
    log.push_back(temp);
    return log;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>> logs;
    for(int i = 0 ; i < record.size(); i++){
        logs.push_back(strtok(record[i]));
        if(logs[i][0] == "Enter"){
            if(m.count(logs[i][1]) > 0){
                m.find(logs[i][1])->second = logs[i][2];
            }else{
                m.insert(make_pair(logs[i][1], logs[i][2]));           
            }
        }else if(logs[i][0] == "Change"){
            m.find(logs[i][1])->second = logs[i][2];
        }
    }
    
    for(int i = 0; i < logs.size(); i++){
        if(logs[i][0] == "Enter"){
            string temp = "" + m.find(logs[i][1])->second;
            temp += "님이 들어왔습니다.";
            answer.push_back(temp);
        }else if(logs[i][0] == "Leave"){
            string temp = "" + m.find(logs[i][1])->second;
            temp += "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }    
    return answer;
}