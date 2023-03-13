#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define p pair<int,int>
int number;
int root[100000];
vector<p> x;
vector<p> y;
vector<p> z;
vector<pair<int, p>> v;
void input(){
    cin >> number;
    for(int i = 0 ; i< number ;i++){
        root[i] = i;
    }
    for(int i = 0; i < number; i++){
        int a,b,c;
        cin >> a >> b >>c;
        x.emplace_back(a,i);
        y.emplace_back(b,i);
        z.emplace_back(c, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 0; i < number-1 ;i++){
        v.push_back({x[i+1].first - x[i].first, {x[i].second, x[i+1].second}});
        v.push_back({y[i+1].first - y[i].first, {y[i].second, y[i+1].second}});
        v.push_back({z[i+1].first - z[i].first, {z[i].second, z[i+1].second}});
    }
    sort(v.begin(), v.end());
}

int find_root(int x){
    if(x == root[x]) return x;
    return root[x] = find_root(root[x]);
}

void union_root(int x,int y){
    x = find_root(x);
    y = find_root(y);
    if(x!=y) root[x]= y;
}

void kruskal(){
    int answer = 0;
    int idx = 0;
    for(int i = 0 ; i < v.size(); i++){
        pair<int, p> current = v[i];
        int start = current.second.first;
        int end = current.second.second;
        if(find_root(start) == find_root(end)) continue;
        idx++;
        answer += current.first;
        union_root(start, end);
        if(idx == number-1) break;
    }
    cout << answer;
}

int main(){
    input();
    kruskal();
}