#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[5][5];
int dp[5][5];
void init(){
    for(int i =0 ; i < 5; i++){
        for(int j= 0; j< 5; j++){
            visit[i][j] = false;
            dp[i][j] = 0;
        }
    }
}

int bfs(vector<string> v,int a,int b){
    init();
    queue<pair<int,int>> q;
    vector<int> current;
    q.push({a,b});
    visit[a][b] = true;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visit[x][y] = true;
        q.pop();
        for(int i =0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 &&nx < 5 && ny >= 0 && ny < 5 &&  !visit[nx][ny] && v[nx][ny] != 'X'){
                q.push({nx,ny});
                visit[nx][ny] = true;
                dp[nx][ny] = dp[x][y] +1;
                if(v[nx][ny] == 'P' && dp[nx][ny]) current.push_back( dp[nx][ny]);
            }
        }
    }
    for(auto i: current){
        if(i <= 2) return 0;
    }

    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0 ; i < places.size(); i++){
        vector<int> temp;
        for(int j= 0; j< places[0].size();j++){
            for(int z = 0; z< places[0][0].size(); z++){
                if(places[i][j][z] == 'P'){
                    temp.push_back(bfs(places[i], j,z));
                }
            }
        }
        int value =1;
        for(auto i: temp){
            if(i == 0) {
                value = 0;
                break;
            }
        }
        answer.push_back(value);
    }
    return answer;
}