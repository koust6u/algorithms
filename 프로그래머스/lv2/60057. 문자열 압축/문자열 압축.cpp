#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> v;
    int length = s.length()/2 +1;
    for(int i = 1 ; i < s.length(); i++){
        string result;
        string prev = s.substr(0,i);
        int idx = 1;
        for(int j =i; j < s.length(); j += i){
            string current = s.substr(j, i);
            if(current == prev)idx++;
            else{
                if(idx == 1) result += prev;
                else result += to_string(idx) + prev;
                idx = 1;
            }
            if(j+ i >= s.length()){
                if(idx != 1) result += to_string(idx)+ current;
                else result += current;
            }
            prev =current;
        } 
        if(result.length() > 0)v.push_back(result.length());
        
    }
    int min = 1001;
    for(auto i : v){
        if(i < min) min = i;
    }
    if(v.empty()) return 1;
    return min;
}