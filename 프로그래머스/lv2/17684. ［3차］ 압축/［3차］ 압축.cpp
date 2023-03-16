#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<int, string> m;

void init(){
    for(int i = 1 ;i <= 26 ; i++) m[i] =64+i; 
}

int contains(string s){
    for(auto &i: m){
        if(i.second == s) return i.first;
    }
    return 0;
}
vector<int> solution(string msg) {
    vector<int> answer;
    init();
    for(int i = 0 ; i < msg.length() ;){
        string temp ="";
        temp += msg[i];
        int idx = 0;
        bool flag = true;
        while(i+idx < msg.length()){
            if(contains(temp) != 0){
                idx++;
                temp +=  msg[i + idx];
            }else{
                answer.push_back(contains(temp.substr(0, temp.length()-1)));
                m[m.size()+1] = temp;
                flag = false;
                break;
            }
        }
        if(flag){
            answer.push_back(contains(temp.substr(0, temp.length()-1)));
        } 
        i += idx;
    }
    return answer;
}