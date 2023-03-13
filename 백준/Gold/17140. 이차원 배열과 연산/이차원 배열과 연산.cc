#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int matrix[100][100];
int r,c,k;
int row =3 , col = 3;

void input(){
    cin >> r >> c >> k;
    for(int i = 0 ; i < 3; i ++){
        for(int j=0; j <3 ;j++){
            cin >> matrix[i][j];
        }
    }
}
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

vector<int> resorted(vector<int> v){
    map<int,int> map;
    vector<pair<int,int>> temp;
    vector<int> answer;
    for(auto i: v){
        map[i]++;
    }
    for(auto&i: map) temp.emplace_back(i);
    sort(temp.begin(), temp.end(), compare);
    for(int i = 0 ; i < map.size() ; i++){
        answer.push_back(temp[i].first);
        answer.push_back(temp[i].second);
    }
    return answer;
}
void getSize(){
    int x = 0,y= 0;
    for(int i = 0 ; i < 100; i++){
        int max = 0;
        int min = 0;
        for(int j = 0; j < 100 ;j++){
            if(matrix[i][j] != 0){
                max++;
            }
            if(matrix[j][i] != 0){
                min++;
            }
        }
        if(y < max) y=max;
        if(x < min) x=min;
    }
    col = x;
    row = y;

}

void test(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j< row; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void arrange(){
    if(col < row){
        for(int i= 0; i < row; i++){
            vector<int> temp;
            for(int j = 0 ; j <col; j++){
                if(matrix[j][i]!= 0)temp.push_back(matrix[j][i]);
            }
            vector<int> v = resorted(temp);
            for(int j = 0; j < 100; j++){
                if(j < v.size()){
                    matrix[j][i] = v[j];
                }
                else{
                    matrix[j][i] = 0;
                }
            }
        }
    }
    else{
        for(int i= 0; i < col; i++){
            vector<int> temp;
            for(int j = 0 ; j <row; j++){
                if(matrix[i][j]!= 0) temp.push_back(matrix[i][j]);
            }
            vector<int> v = resorted(temp);
            for(int j = 0; j < 100; j++){
                if(j < v.size()){
                    matrix[i][j] = v[j];
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
    }
    getSize();
}
bool check(){
    if(matrix[r-1][c-1] == k) return true;
    return false;
}
int main(){
    input();
    for(int i = 0 ; i <= 100 ; i++){
        if(check()){
            cout << i;
            return 0;
        }
        arrange();
    }
    cout << -1;
}