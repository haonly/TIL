#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &s1, const string &s2){
    return (s1 + s2 > s2 + s1) ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    for(int i = 0; i < numbers.size(); i++){
        num.push_back(to_string(numbers[i]));
    }
    sort(num.begin(), num.end(), cmp);
    
    for(string str : num){
        answer += str;
    }
    if(answer[0] == '0')
        return 0;
    return answer;
}