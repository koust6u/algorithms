#include <string>
#include <vector>
#include <queue>
using namespace std;
int dp[1000001];
int solution(int x, int y, int n) {
    int answer = 0;
    queue<int> q;
    fill(dp, dp+1000001, -1);
    q.push(x);
    dp[x] = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i: {current*2, current*3, current+ n}){
            if(dp[i] == -1 &&  i >=  x && i <= y ){
                dp[i] = dp[current]+1;
                q.push(i);
            }
        }
    }

    return dp[y];
}