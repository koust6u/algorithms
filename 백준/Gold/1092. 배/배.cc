#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    vector<int> crane;
    vector<int> box;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        crane.push_back(n);
    }
    cin >> M;
    for(int i = 0; i < M;i++){
        int m;
        cin >> m;
        box.push_back(m);
    }
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    int count = 0;
    if(crane.back() < box.back()){
        cout << -1;
        return 0;
    }
    while(!box.empty()){
        count++;
        for(int i = crane.size()-1; i>= 0; i--){
            for(int j = box.size()-1; j >= 0; j--){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    cout << count;
    return 0;
}