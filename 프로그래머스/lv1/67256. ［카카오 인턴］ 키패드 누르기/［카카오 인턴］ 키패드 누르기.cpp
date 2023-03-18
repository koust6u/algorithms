#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,int> _right = {3, 2};
pair<int,int> _left = {3,0};
bool visit[4][3], visit2[4][3];
int dp[4][3], dp2[4][3];

void init(){
    for(int i = 0 ; i < 4; i++){
        for(int j= 0; j< 3; j++){
            dp[i][j] = 0;
            dp2[i][j] = 0;
            visit[i][j] = false;
            visit2[i][j] =false;
        }
    }
}
int dfs(int a, int b, char h){
    init();
    queue<pair<int,int>> q, q2;
    q.push({_left.first,_left.second});
    q2.push({_right.first, _right.second});
    visit2[_right.first][_right.second] = true;
    visit[_left.first][_left.second] = true;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < 4 &&ny >=0 && ny < 3 &&!visit[nx][ny]){
                visit[nx][ny] = true;
                dp[nx][ny] = dp[x][y] +1;
                q.push({nx,ny});
            }
        }
    }
    while(!q2.empty()){
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < 4 && ny >= 00 && ny < 3&&!visit2[nx][ny]){
                visit2[nx][ny] = true;
                dp2[nx][ny] = dp2[x][y] +1;
                q2.push({nx,ny});
            }
        }
    }
    int l = dp[a][b];
    int r = dp2[a][b];
    for(int i = 0; i < 4; i++){
        for(int j= 0; j< 3; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 4; i++){
        for(int j= 0; j< 3; j++){
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    if(l < r) {
        _left = {a, b};
        return -1;
    }
    else if(l == r) {
        if(h == 'R') _right = {a,b};
        else _left = {a,b};
        return 0;
    }
    else {
        _right = {a,b};
        return 1;
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    char h =toupper(hand[0]); 
    int x, y;
    for(int i = 0; i < numbers.size(); i++){
        int now = numbers[i];
        if(now == 1 || now == 4 || now == 7) {
            answer += 'L';
            if(now == 1) x = 0;  
            else if(now == 4) x = 1;
            else x=2;
            y = 0;
            _left = {x,y};
        }
        else if(now == 3|| now == 6 || now == 9) {
            answer += 'R';
            if( now  == 3) x =0;
            else if(now == 6) x = 1;
            else x = 2;
            y = 2;
            _right = {x,y};
        }
        else{
            int flag;
            if(now == 2) flag = dfs(0,1,h);
            else if(now == 5) flag = dfs(1,1,h);
            else if(now == 8)flag = dfs(2,1,h);
            else if(now == 0)flag = dfs(3,1,h);
            if(flag == 0) answer += h;
            else if(flag == -1) answer += 'L';
            else answer += 'R';
        }
    }
    return answer;
}