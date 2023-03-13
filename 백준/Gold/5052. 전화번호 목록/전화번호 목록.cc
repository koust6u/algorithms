#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int test;
    cin >> test;
    vector<string>answer;

    for(int t = 0; t < test; t++) {
        bool flag = false;
        int number;
        cin >> number;
        vector<string> v(number);
        for (int i = 0; i < number; i++) {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        for(int i = 0 ; i < v.size()-1; i++){
            if(v[i+1].substr(0, v[i].length())== v[i]) flag = true;
        }
        if(flag) answer.emplace_back("NO");
        else answer.emplace_back("YES");
    }
    for(auto i: answer){
        cout << i << "\n";
    }
}