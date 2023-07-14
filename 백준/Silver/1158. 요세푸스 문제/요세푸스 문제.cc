#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i =1; i <= n; i++){
        q.push(i);
    }
    vector<int> answer;
    while(!q.empty()){
        for(int i = 0 ; i < k-1; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int temp = q.front();
        q.pop();
        answer.push_back(temp);
    }

    cout << "<";
    for(int i =0; i < answer.size()-1; i++){
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size()-1] << ">";
}