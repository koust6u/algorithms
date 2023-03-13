#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define p pair<int, pair<int,int>>
using namespace std;
int v,e;
vector<p> vec;
int answer = 0;
int *root;
void input(){
    cin >> v >> e;
    root = new int[v+1];
    for(int i = 1 ; i <= v; i++) root[i] = i;
    for(int i = 0 ; i < e; i++){
        int x,y,z;
        cin >> x >> y >> z;
        vec.push_back({z,{x,y}});
    }
    sort(vec.begin(), vec.end());
}

int find_root(int x){
    if(root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

void union_root(int x, int y){
    x = find_root(x);
    y = find_root(y);
    if(x != y)root[y] = x;
}

void kruskal(){
    int idx = 0;
    for(int i = 0 ; i < e; i++){
        p current = vec[i];
        int start = current.second.first;
        int end = current.second.second;
        if(find_root(start) == find_root(end)) continue;
        union_root(start, end);
        answer += current.first;
        idx++;
        if( idx== v-1) break;
    }
    cout << answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    kruskal();
}