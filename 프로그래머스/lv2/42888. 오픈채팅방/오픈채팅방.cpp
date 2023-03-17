#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
map <string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<int, string>> types;
    for(auto i : record){
        stringstream ss(i);
        string temp;
        string list[3];
        int idx = 0;
        while(getline(ss, temp, ' ')){
            list[idx++] = temp;
        }
        if(list[0] == "Enter") types.emplace_back(0, list[1]);
        else if(list[0] == "Leave") types.emplace_back(1, list[1]);
        if(list[0] == "Enter" || list[0] == "Change"){
            m[list[1]] = list[2];
        }
    }
    for(auto i: types){
        if(i.first == 0) answer.push_back(m[i.second]+"님이 들어왔습니다.");
        else answer.push_back(m[i.second] + "님이 나갔습니다.");
    }
    return answer;
}