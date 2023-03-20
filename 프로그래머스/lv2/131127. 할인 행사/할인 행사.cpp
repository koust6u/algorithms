#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool contains(map<string,int> m, string s){
    for(auto i: m){
        if(i.first == s && i.second != 0)return true;
    }
    return false;
}

int totalsum(map<string,int> m){
    int sum = 0;
    for(auto i : m){
        sum += i.second;
    }
    return sum;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> m;
    for(int i =0 ; i < want.size(); i++)m[want[i]] = number[i];
    for(int i = 0 ; i <= discount.size()- 10; i++){
        map<string, int> temp = m;
        bool flag = false;
        for(int j= i;  j< i+10; j++){
            if(!contains(temp,discount[j])){
                flag = true;
                break;
            }
            temp[discount[j]]--;
        }
        if(totalsum(temp) == 0 && !flag)answer++;
    }
    return answer;
}