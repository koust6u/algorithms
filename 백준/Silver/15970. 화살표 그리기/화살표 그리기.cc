#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int number,answer = 0;
    cin >> number;
    map<int, vector<int>> map;
    for(int i = 0; i < number; i++){
        int distance, color;
        cin >> distance >> color;
        map[color].emplace_back(distance);
    }

    for(auto i: map){
        sort(i.second.begin(), i.second.end());
        int prev = i.second[1] - i.second[0];
        answer += prev;
        for(int j= 1 ; j < i.second.size()-1; j++){
            int next = i.second[j+1] - i.second[j];
            answer += min(prev, next);
            prev = next;
        }
        answer += prev;
    }
    cout << answer ;
}