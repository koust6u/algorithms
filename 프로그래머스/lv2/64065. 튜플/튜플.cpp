#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

bool visit[100001];

bool compare(vector<int> a, vector<int> b){
    return a.size() < b.size();
}
vector<vector<int>> parse(string s){
    string temp;
    stringstream ss(s);
    vector<string> v, v2;
    while(getline(ss, temp, '}')){
        v.push_back(temp);
    }
    for(auto i: v){
        if(i.length()> 2){
            v2.push_back(i.substr(2));
        }
    }
    vector<vector<int>> answer;
    for(auto i: v2){
        stringstream ss2(i);
        string temp2;
        vector<int> a;
        while(getline(ss2, temp2, ',')){
            a.push_back(stoi(temp2));
        }
        answer.push_back(a);
    }

    return answer;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> list = parse(s);
    sort(list.begin(),list.end(), compare);
    
    for(auto i: list){
        for(int j = 0; j< i.size(); j++){
            if(!visit[i[j]]) {
                answer.push_back(i[j]);
                visit[i[j]] = true;
            }
        }
    }
    return answer;
}