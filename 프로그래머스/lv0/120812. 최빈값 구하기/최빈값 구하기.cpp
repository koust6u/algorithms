#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int,int> m;
    for(auto i : array){
        m[i]++;
    }
    int max = 0;
    for(auto i: m){
        if(i.second > max) {
            max = i.second;
            answer = i.first;
        }
    }
    vector< int > v;
    for(auto i: m){
        if(max == i.second){
            v.push_back(i.first);
        }
    }
    if(v.size() > 1) return -1;
    return answer;
}