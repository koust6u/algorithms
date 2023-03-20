#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int global;
bool compare(vector<int> a,vector<int> b){
    if(a[global] == b[global]){
        return a[0] > b[0];
    }
    return a[global] < b[global];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    global= col-1;
    sort(data.begin(), data.end(), compare);
    int xorSum = 0;
    for(int i = row_begin-1 ; i < row_end; i++){
        int mod = i+1;
        int sum = 0;
        for(int j= 0 ; j < data[0].size(); j++){
            sum += (data[i][j]%mod);
        }
        xorSum ^= sum;
    }
    return xorSum;
}