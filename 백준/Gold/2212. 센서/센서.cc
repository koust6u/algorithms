#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int sensor[10000];
int main(){
    cin >> n >> k;
    for(int i = 0 ; i < n; i++)cin >>sensor[i];
    sort(sensor, sensor+n,greater<int>());
    int answer = sensor[0] - sensor[n - 1];
    for(int i = 0; i < n-1; i++){
        sensor[i] = sensor[i] - sensor[i+1];
    }
    sort(sensor, sensor+n-1,greater<int>());
    for(int i = 0 ; i < k-1; i++){
        answer -= sensor[i];
    }
    if(n <= k){
        cout << 0;
        return 0;
    }
    cout << answer;

}
