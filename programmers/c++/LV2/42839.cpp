#include <bits/stdc++.h>
using namespace std;

int number_arr[10];
bool prime_arr[10000000];

void make_prime_arr(int num){
    prime_arr[0] = true;
    prime_arr[1] = true;
    for(int i = 2; i < num + 1; i++){
        if(!prime_arr[i]){
            for(int j = i * 2; j < num + 1; j += i){
                prime_arr[j] = true;
            }
        }
    }
}

bool chk_num(int num){
    int temp[10];
    for(int i = 0; i < 10; i++){
        temp[i] = 0;
    }
    do{
        temp[num % 10]++;
        num /= 10;
    }while(num > 0);
    for(int i = 0; i < 10; i++){
        if(temp[i] > number_arr[i]){
            return false;
        }
    }
    return true;
}


int solution(string numbers) {
    int answer = 0;
    int min, max, len = numbers.length();
    sort(numbers.begin(), numbers.end(), greater<int>());
    max = stoi(numbers);
    min = numbers[numbers.length() - 1] - '0';
    make_prime_arr(max);
    for(int i = 0; i < len; i++){
        number_arr[numbers[i] - '0']++;
    }
    for(int i = min; i < max + 1; i++){
        if(!prime_arr[i] && chk_num(i)){
            answer++;
        }
    }    
    return answer;
}