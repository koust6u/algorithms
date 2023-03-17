#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string translator(int n, int k){
   string s = "";
    while(n != 0){
        s = to_string((n%k)) +s;
        n /= k;
    }
    return s;
}

vector<string> split(string s){
    vector<string> v;
    string temp = "";
    bool flag = false;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] != '0') {
            temp.push_back(s[i]);
            flag = true;
        }
        else if(flag && s[i] == '0'){
            v.push_back(temp);
            temp = "";
            flag = false;
        }
    }
    if(temp.length() > 0) v.push_back(temp);
    
    return v;
}


bool isPrime(long long n){
    if(n < 2) return false;
    for(long long i = 2 ; i <= sqrt(n) ; i++)
        if(n%i ==0) return false;
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s= translator(n, k);
    vector<string> v = split(s);
    for(auto i : v){
        if(isPrime(stoll(i)))answer++;
    }
    return answer;
}