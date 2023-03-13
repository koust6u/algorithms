#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(string numbers){
    int answer = 0;
    vector<char> v;
    for(char & number : numbers){
        v.push_back(number);
    }
    sort(v.begin(), v.end());

    vector<int> nums;
    do{
        string temp ="";
        for(int i = 0 ; i < v.size(); i++){
            temp.push_back(v[i]);
            nums.push_back(stoi(temp));
        }
    }while(next_permutation(v.begin(), v.end()));

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for(auto i: nums){
        bool flag = true;
        if(i < 2) flag = false;
        for(int j = 2; j < i; j++){
            if(i % j == 0) {
                flag = false;
                cout << i << endl;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}
