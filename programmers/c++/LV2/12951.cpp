#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    bool flag = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            flag = true;
            continue;
        }
        if(flag){
            if(islower(s[i])){
                s[i] = toupper(s[i]);
            }
            flag = false;
        }
        else{
            if(isupper(s[i])){
                s[i] = tolower(s[i]);
            }
        }        
    }   
    return s;
}

int main() {
    string s = "3people unFollowed me";
    string result = solution(s);
    cout << result << "\n";
}