#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >>x >> y;
        v.emplace_back(x,y);
    }
    sort(v.begin(), v.end());
    vector<pair<int,int>> answer;
    answer.push_back(*v.begin());
    pair<int,int> prev = *v.begin();
    for(int i = 1; i < n; i++){
        if(prev.second >= v[i].first){
            answer[answer.size()-1].second = max(v[i].second,prev.second);
        }
        else{
            answer.push_back(v[i]);
        }
        prev = answer[answer.size()-1];
    }
    int result =0;
    for(auto i: answer){
        result += i.second - i.first;
    }
    cout << result;
}