#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isNumber(char a){
    if(a >= '0'  && a <= '9')return true;
    return false;
}
bool compare(string a, string b){
    string headA = "", headB = "";
    string numberA = "", numberB = "";
    bool flag = false;
    string A="" ,B="";
    for(int i =0 ; i < a.length(); i++){
        if(isNumber(a[i])){
            numberA += a[i];
            flag = true;
        }
        if(!flag && !isNumber(a[i])){
            headA += a[i];
        }
        if(flag && !isNumber(a[i]))break;
    }
    flag = false;
    for(int i =0 ; i < b.length(); i++){
        if(isNumber(b[i])){
            numberB += b[i];
            flag = true;
        }
        if(!flag && !isNumber(b[i])){
            headB += b[i];
        }
        if(flag && !isNumber(b[i]))break;
    }
    for(int i = 0 ; i < headA.length(); i++){
        A += tolower(headA[i]);
    }
    for(int i = 0; i < headB.length(); i++){
        B += tolower(headB[i]);
    }
    if(A== B) return stoi(numberA) < stoi(numberB);
    return A < B;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(auto& i: files){
        answer.push_back(i);
    }
    stable_sort(answer.begin(), answer.end(), compare);
    return answer;
}