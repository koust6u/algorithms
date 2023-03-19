#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool visit[100][100];
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};

int bfs(vector<string> v,int a, int b){
    int answer = v[a][b] -'0';
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size() && !visit[nx][ny] && v[nx][ny] != 'X'){
                visit[nx][ny] = true;
                q.push({nx,ny});
                answer += v[nx][ny] - '0';
            }
        }
    }
    return answer;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j=0; j < maps[i].size(); j++){
            if(maps[i][j] != 'X' && !visit[i][j]){
                answer.push_back(bfs(maps,i,j));
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()) return {-1};
    return answer;
}