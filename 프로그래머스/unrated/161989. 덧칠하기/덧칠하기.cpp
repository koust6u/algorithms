#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    bool *visit = new bool[n+1];
    for(int i = 0; i <=n; i++) visit[i] = false;
    for(int i= 0 ; i < section.size(); i++){
        visit[section[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        if(visit[i]){
            for(int j =0; j< m; j++){
                if(i+j < n+1) visit[i+j] = false;
                else break;
            }
            answer++;
        }
    }
    return answer;
}