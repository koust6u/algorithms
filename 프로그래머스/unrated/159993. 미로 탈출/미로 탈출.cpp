#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dp[100][100];
bool visit[100][100];
pair<int,int> start;
pair<int,int> _exit;
pair<int,int> lever;

void config(vector<string> v){
    for(int i = 0 ; i < v.size() ;i++){
        for(int j= 0 ; j< v[0].size(); j++){
            if(v[i][j] == 'E') _exit = {i,j};
            else if(v[i][j] =='L')lever = {i,j};
            else if(v[i][j] == 'S')start = {i,j};
        }
    }
}
void init(vector<string> v){
    for(int i = 0 ; i <v.size(); i++){
        for(int j= 0; j < v[0].size(); j++){
            dp[i][j]=0;
            visit[i][j] = false;
        }
    }
}
int toLever(vector<string> v){
    config(v);
    queue<pair<int,int>> q;
    q.push(start);
    visit[start.first][start.second] = true;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < v.size() && ny >=0 && ny < v[0].size() && !visit[nx][ny] && v[nx][ny]!= 'X'){
                q.push({nx,ny});
                visit[nx][ny] = true;
                dp[nx][ny] = dp[x][y]+1; 
            }
        }
    }
    
    if(dp[lever.first][lever.second] == 0) return -1;
    return dp[lever.first][lever.second];
}

int toExit(vector<string> v){
    queue<pair<int,int>> q;
    init(v);
    q.push(lever);
    visit[lever.first][lever.second] = true;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < v.size() && ny >=0 && ny < v[0].size() && !visit[nx][ny] && v[nx][ny] != 'X'){
                q.push({nx,ny});
                visit[nx][ny] = true;
                dp[nx][ny] = dp[x][y]+1; 
            }
        }
    }
    
    if(dp[_exit.first][_exit.second] == 0) return -1;
    return dp[_exit.first][_exit.second];
}

int solution(vector<string> maps) {
    int leverValue = toLever(maps);
    int exitValue = toExit(maps);
    if(leverValue == -1 || exitValue == -1) return -1;
    
    return leverValue + exitValue;
}