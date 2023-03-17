#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void crash(vector<string> &v){
    vector<pair<int,int>> p;
    int dx[3] = {0,1,1};
    int dy[3] = {1,0,1};
    for(int i =  0; i < v.size(); i++){
        for(int j = 0; j< v[i].length(); j++){
            int idx = 0;
            for(int k = 0; k < 3; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(0<= nx && nx < v.size() && ny >= 0 && ny < v[i].length() && v[nx][ny] == v[i][j]){
                    idx++;
                    if(idx == 3) p.emplace_back(i,j);
                }
            }
        }
    }
    for(auto i: p){
        v[i.first][i.second] = '0';
        v[i.first+1][i.second] =  '0';
        v[i.first+1][i.second+1] = '0';
        v[i.first][i.second+1] = '0';
    }
}

void change(vector<string>& v){
    for(int i = 0 ; i < v[0].length(); i++){
        string temp;
        for(auto & j : v){
            if(j[i] != '0') temp += j[i];
        }
        while(temp.length() < v.size()){
            temp = '0' + temp;
        }
        for(int j = 0; j < v.size(); j++){
            v[j][i] = temp[j];
        }
    }
}

int getValue(const vector<string>& board){
    int answer = 0;
    for(const auto& i: board){
        for(char j : i){
            if(j == '0') answer++;
        }
    }
    return answer;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int temp =0;
    while(true){
        crash(board);
        change(board);
        temp= getValue(board);
        if(temp == answer) break;
        else answer = temp;
    }
    return answer;
}

int main(){
    vector<string> v ={"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
    cout << solution(6,6,v);
}