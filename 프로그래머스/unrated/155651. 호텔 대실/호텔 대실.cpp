#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
int dp[25][60];
int _max = 0;

void parse(vector<string> v){
    stringstream ss(v[0]);
    stringstream ss2(v[1]);
    string temp;
    int first[2], second[2];
    int idx = 0;
    while(getline(ss,temp,':'))first[idx++] = stoi(temp);
    idx = 0;
    while(getline(ss2,temp,':'))second[idx++] = stoi(temp);
    second[1] += 9;
    if(second[1] > 59) {
        second[0]++;
        second[1] -= 60;
    }
    if(first[0] == second[0]){
        for(int i = first[1]; i <= second[1]; i++){
            dp[first[0]][i]++;
            if(dp[first[0]][i] > _max) _max = dp[first[0]][i];
        }
    }
    else{
        for(int i = first[1] ; i < 60; i++){
            dp[first[0]][i]++;
            if(dp[first[0]][i] > _max) _max = dp[first[0]][i];
        }
        for(int i = first[0]+1; i < second[0] ;i++){
            for(int j = 0; j < 60; j++) {
                dp[i][j]++;
                if(dp[i][j] > _max) _max = dp[i][j];
            }
        }
        for(int i = 1 ; i <= second[1] ;i++){
            dp[second[0]][i]++;
            if(dp[second[0]][i] > _max) _max = dp[second[0]][i];
        }
                
    }
}
int solution(vector<vector<string>> book_time) {
    for(auto i : book_time){
        parse(i);
    }
    
    for(int i = 1; i < 24; i++){
        for(int j= 0 ; j< 60; j++){
            cout << i << "clock " << j << "mintue :" << dp[i][j] << endl; 
        }
    }
    return _max;
}