#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> v;
    int temp, cnt = 0;
    
    for(int i = 1; i < s.length()-1; i++){
        if(s[i] == '{'){
            temp = 0;
            for(int j = i + 1; j < s.length()-1; j++){
                if(s[j] == '}'){
                    cnt++;
                    v.push_back(temp);
                    break;                                        
                }else if(s[j] == ','){                    
                    v.push_back(temp);
                    temp = 0;
                }else{
                    temp = temp * 10 + (s[j] - '0');
                }          
            }
        }
    }
    sort(v.begin(), v.end());
    v.push_back(100001);
    vector<int> arr(cnt);
    for(int i = 0 ; i < v.size() - 1; i++){
        int temp_cnt = 1;
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] != v[j]){
                arr[cnt - temp_cnt] = v[i];
                i = j - 1;
                break;
            }else{
                temp_cnt++;
            }
            if(j == v.size() - 1){
                arr[cnt - temp_cnt] = v[i];
            }
        }        
    }
    
    for(int i = 0; i < cnt; i++){
        answer.push_back(arr[i]);
    }
    
    
    return answer;
}