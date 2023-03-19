#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int storey) {
    int answer = 0;
    string s = to_string(storey);
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == '5'){
            if(s[i+1] >= '5') s[i+1] = s[i+1]+1;
            answer += 5;
        }
        else if(s[i] >'5'){
            int temp =10-(s[i] - '0');
            s[i+1] = s[i+1]+1;
            answer += temp;
        }
        else{
            answer += s[i] - '0';
        }
    }
    if(s[s.length()-1] - '0' > 5) answer += (1+ (10 -(s[s.length()-1] -'0')));
    else answer += s[s.length()-1]-'0';
    
    return answer;
}