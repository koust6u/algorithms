#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//J(A,B) = A,B 합집합 /교집합; if A = 0 B = 0 -> 1;
//영문자 제회 버리고 2개씩나눔
//case Insenstive
// 유사도 * 65536 -> 소수점 버림
bool isAlphabet(char c){
    if(c >= 'a' && c <= 'z') return true;
    return false;
}
vector<string> preprocess(string s){
    string temp = "";
    string result = "";
    for(int i = 0 ; i < s.length(); i++){
        temp += tolower(s[i]);
    }
    vector<string> v;
    vector<string> ret;
    for(int i = 0; i < temp.length(); i++){
         v.emplace_back(temp.substr(i,2));
    }
    for(auto i: v){
        if(isAlphabet(i[0]) && isAlphabet(i[1]))ret.push_back(i);
    }
    return ret;
}

int sub(vector<string> s1, vector<string> s2){
    int result = 0;
    set<string> s;
    for(auto i: s1)
        s.insert(i);
    
    for(auto i: s){
        int num1 = 0, num2= 0;
        for(int j = 0 ; j <s1.size(); j++){
            if(i == s1[j])num1++;
        }
        for(int j= 0; j< s2.size(); j++){
            if(i == s2[j])num2++;
        }
        result += min(num1, num2);
    }
    return result;
}

int add(vector<string> s1, vector<string> s2){
    int result = 0;
    set<string> s;
    for(auto i: s1)
        s.insert(i);
    
    for(auto i: s2)
        s.insert(i);
    
    for(auto i: s){
        int num1 = 0, num2 =0;
        for(int j = 0 ; j <s1.size(); j++){
            if(i == s1[j])num1++;
        }
        for(int j= 0; j< s2.size(); j++){
            if(i == s2[j])num2++;
        }
        result += max(num1, num2);
    }
    return result; 
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1 = preprocess(str1);
    vector<string> s2 = preprocess(str2);
    int inter = sub(s1, s2);
    int exclusive = add(s1,s2);
    if(inter == 0 && exclusive == 0) return 65536;
    double d = ((double)inter/(double)exclusive)* 65536;
    return d;
    
}