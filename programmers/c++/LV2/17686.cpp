#include <bits/stdc++.h>
using namespace std;

vector<string> parse(string str) {
    int number = -1, tail = str.length();
    for(int i = 0; i < str.length(); i++) {
        if(isdigit(str[i])) {
            number = i;
            break;
        }                
    }
    
    int cnt = 0;
    for(int i = number; i < str.length(); i++){
        if(!isdigit(str[i])) {
            tail = i;
            break;
        }
        cnt++;
        if(cnt > 5) {
            tail = i;
            break;
        }
    }
    return {str.substr(0, number), str.substr(number, tail), str.substr(tail, str.length())};
}

bool compare(string a, string b) {
    vector<string> s1 = parse(a);
    vector<string> s2 = parse(b);
    
    string head1 = "";
    for(int i = 0; i < s1[0].size(); i++) {
        head1 += tolower(s1[0][i]);
    }
    
    string head2 = "";
    for(int i = 0; i < s2[0].size(); i++) {
        head2 += tolower(s2[0][i]);        
    }
    
    if(head1 != head2) {
        return head1 < head2;
    }
    
    return stoi(s1[1]) < stoi(s2[1]);
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}