#include <iostream>
using namespace std;

int solution(int n, int a, int b){
    int answer = 1;
    while(1){
        if((a + 1) / 2 == (b + 1) / 2){
            return answer;
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }
}