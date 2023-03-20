#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define p pair<int,pair<int,int>>
using namespace std;
int *root;
int n,m;
vector<pair<int,pair<int,int>>> v;

void input(){
    cin >> n >>m;
    root = new int[n];
    for(int i = 0; i < n; i++) root[i] = i;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>> a>> b>> c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(), v.end());
}

int find_root(int x){
    if(root[x] == x) return x;
    return root[x] = find_root(root[x]);
}

void union_root(int x, int y){
    x = find_root(x);
    y = find_root(y);
    if(x != y) root[y] =x;
}

int kruskal(){
    int idx =0;
    int answer = 0;
    for(int i = 0 ; i < v.size(); i++){
        p current = v[i];
        int start = current.second.first;
        int end = current.second.second;
        if(find_root(start) == find_root(end)) continue;
        union_root(start,end);
        answer += current.first;
        idx++;
        if(idx == n-2)break;
    }
    return answer;
}
int main(){
    input();
    cout << kruskal();

}
