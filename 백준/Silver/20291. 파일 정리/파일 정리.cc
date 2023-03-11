#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> a, pair<string,int> b){
    return a.first < b.first;
}

int main(){
    int number;
    cin >> number;
    vector<pair<string,int>> v;
    map <string, int> map;
    for(int i = 0 ; i < number; i++){
        string s;
        cin >> s;
        stringstream ss = stringstream(s);
        string arr[2];
        string temp;
        int k = 0;
        while(getline(ss,temp,'.')){
            arr[k] = temp;
            k++;
        }
        map[arr[1]]++;
    }
    for(auto j: map){
        v.emplace_back(j);
    }
    sort(v.begin(),v.end(), compare);
    for(auto i : v){
        cout << i.first << " " << i.second << endl;
    }
}