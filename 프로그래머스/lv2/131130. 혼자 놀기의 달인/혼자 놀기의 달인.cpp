#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[100];
int _count = 1;

void dfs(vector<int> cards,int start, int current){
    if(start == cards[current]) return;
  
    if(!visit[cards[current]]){
        dfs(cards,start, cards[current]);
        visit[cards[current]] = true;
        _count++;
    }
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> answers;
    for(int i =0 ; i < cards.size(); i++){
        cards[i] = cards[i]-1;
    }
    for(int i = 0; i < cards.size(); i++){
        _count = 0;
        if(!visit[i]){
            visit[i] = true;
            _count = 1;
            dfs(cards,i,i);
        }
        answers.push_back(_count);
    }
    
    sort(answers.begin(), answers.end(), greater<int>());
    bool flag = false;
    if(answers[1] < 1) return 0;
    
    return answers[0] * answers[1];
}