#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2= 0;
    int size = queue1.size();
    for(int i = 0; i < size; i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    queue<int> q1,q2;
    for(auto i: queue1){
        q1.push(i);
    }
    for(auto i: queue2){
        q2.push(i);
    }
    long long target = (sum1 + sum2) / 2;
    int answer = 0;
    long long temp;
    while(answer < 300001){
        if(sum1 == sum2) break;
        if(sum1 < target){
            temp = q2.front();
            q2.pop();
            q1.push(temp);
            sum1 += temp;
            sum2 -= temp;
            answer++;
        }
        else{
            temp = q1.front();
            q1.pop();
            q2.push(temp);
            sum2 += temp;
            sum1 -= temp;
            answer++;
        }
    }
    if(answer == 300001) return -1;
    return answer;
}