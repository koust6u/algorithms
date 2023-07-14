#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> s;
    for(int i = n; i > 0 ; i--){
        s.push_back(i);
    }

    while(s.size() > 1){
        s.pop_back();
        int temp = s.back();
        s.pop_back();
        s.push_front(temp);
    }
    cout << s.front() << endl;

}