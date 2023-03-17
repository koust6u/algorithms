#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;


int trans(string a){
    stringstream ss(a);
    string temp;
    string list[2];
    int idx = 0;
    while(getline(ss, temp, ':')){
        list[idx++] = temp;
    }
    int answer = stoi(list[0])*60 + stoi(list[1]);
    return answer;
}
bool compare(pair<string, string> a, pair<string,string> b){
    if(a.second == b.second) return a.first< b.first;
    return a.second < b.second;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, string>> v;
    for(const auto& i: records){
        stringstream ss(i);
        string temp;
        string list[3];
        int idx = 0;
        while(getline(ss, temp, ' ')){
            list[idx++] = temp;
        }
        pair<string , string> p = make_pair(list[0], list[1]);
        v.emplace_back(p);
    }

    sort(v.begin(),v.end(), compare);
    for(auto i: v){
        cout << i.first << " " << i.second << endl;
    }
    for(int i = 0 ; i < v.size();){
        int idx = 0;
        vector<pair<string,string>> temp;
        while(v[i].second == v[i+idx].second){
            temp.push_back(v[i+idx]);
            idx++;
        }

        if(idx %2 !=0){
            string a = temp[0].second;
            temp.emplace_back("23:59", a);
        }

        int time = 0;
        for(int j=0; j< temp.size();){
            int x = trans(temp[j].first);
            int y = trans(temp[j+1].first);
            time += (y -x);
            j+=2;
        }
        int sum = 0;
        time -= fees[0];
        sum += fees[1];
        if(time > 0){
            if(time % fees[2] == 0) sum += fees[3]*(time/fees[2]);
            else sum += fees[3] * ((time/fees[2]) +1);
        }
        i += idx;
        answer.push_back(sum);
    }
    return answer;
}
