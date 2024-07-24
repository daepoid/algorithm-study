#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int c;
    while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        answer = lcm(answer, arr[i]);
    }    
    return answer;
}