#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int a = common[1] - common[0];
    int b = common[2] - common[1];
    if(a == b){
        answer = common[common.size()-1] + a;
    }
    else{
        int temp =b/a;
        answer = common[common.size()-1] * temp;
    }
    return answer;
}