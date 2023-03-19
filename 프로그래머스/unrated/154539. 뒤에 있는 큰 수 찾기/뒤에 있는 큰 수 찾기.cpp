#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers){
    vector<int> answer(numbers.size(), -1);
    stack<pair<int,int>> stack;

    for(int i = 0; i < numbers.size(); i++){
        while(!stack.empty()){
            pair<int,int> top = stack.top();

            if(top.first >= numbers[i])break;
            answer[top.second] = numbers[i];
            stack.pop();
        }
        stack.push({ numbers[i], i});
    }
    return answer;
}

int main(){

}