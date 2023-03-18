#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> set;
    for(int i = 1; i <= elements.size(); i++){
        for(int j= 0; j < elements.size(); j++){
            int temp = 0;
            for(int z = 0; z < i; z++) temp += elements[(j+z)% elements.size()];
            set.insert(temp);
        }
    }
    answer = set.size();
    return answer;
}