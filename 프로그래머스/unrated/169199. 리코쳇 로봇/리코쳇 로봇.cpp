#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[100][100];
int dp[100][100];
pair<int,int> start;
pair<int,int> dest;
bool findStart(vector<string> v){
    for(int i =0 ; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 'R') {
                start = {i, j};
                return true;
            }
        }
    }
    return false;
}

void findDest(vector<string> v){
    for(int i = 0; i < v.size() ; i++){
        for(int j = 0 ; j< v[0].size(); j++){
            if(v[i][j] == 'G') dest = {i,j};
        }
    }
}
pair<int,int> left(vector<string> v, int x,int y){
    int b = y;
    while(b-1 >= 0 && v[x][b-1] !='D')b--;
    return {x,b};
}

pair<int,int> right(vector<string> v, int x, int y){
    int b = y;
    while(b+1 < v[0].size() && v[x][b+1] != 'D')b++;
    return {x,b};
}

pair<int,int> up(vector<string> v, int x,int y){
    int a = x;
    while(a-1 >=0 && v[a-1][y] != 'D') a--;
    return {a,y};
}
pair<int,int> down(vector<string> v, int x ,int y){
    int a = x;
    while(a+1 < v.size() && v[a+1][y] != 'D')a++;
    return {a,y};
}

void bfs(vector<string> v){
    queue<pair<int,int>> q;
    q.push({start.first, start.second});
    visit[start.first][start.second] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y= q.front().second;
        q.pop();
        pair<int,int> temp;
        temp = left(v,x,y);
        if(!visit[temp.first][temp.second]){
            q.push(temp);
            visit[temp.first][temp.second] = true;
            dp[temp.first][temp.second] = dp[x][y] +1;
        }
        temp = right(v,x,y);
        if(!visit[temp.first][temp.second]){
            q.push(temp);
            dp[temp.first][temp.second] = dp[x][y] +1;
            visit[temp.first][temp.second] = true;

        }
        temp = up(v,x,y);
        if(!visit[temp.first][temp.second]){
            q.push(temp);
            dp[temp.first][temp.second] = dp[x][y] +1;
            visit[temp.first][temp.second] = true;

        }
        temp = down(v,x,y);
        if(!visit[temp.first][temp.second]){
            q.push(temp);
            dp[temp.first][temp.second] = dp[x][y] +1;
            visit[temp.first][temp.second] = true;

        }
    }
}
int solution(vector<string> board) {
    if(!findStart(board))return -1;
    findDest(board);
    bfs(board);
    if(dp[dest.first][dest.second] == 0) return -1;
    return dp[dest.first][dest.second];
}

