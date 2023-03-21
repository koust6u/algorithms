#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int> pq;
    int soldier = n;
    int chance = k;
    for(int i =0 ; i < enemy.size();i++){
        soldier -= enemy[i];
        pq.push(enemy[i]);
        
        if(soldier < 0){
            if(chance > 0 && !pq.empty()){
                soldier += pq.top();
                pq.pop();
                chance--;
            }
            else{
                answer = i;
                break;
            }
        }
    }
    return answer;
}