#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v[2000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    int answer = 0;
    for(int z = 0 ; z < n; z++){
        int i = 0,j = n-1;
        int value = v[z];
        while(i < j){
            int sum = v[i] + v[j];
            if(sum ==value) {
                if(i != z && j != z){
                    answer++;
                    break;
                }
                else if(z == i) i++;
                else if(z == j) j--;
            }
            else if(sum < value) i++;
            else j--;
        }
    }
    cout << answer;
}