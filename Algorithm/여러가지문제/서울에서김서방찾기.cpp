#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string kim = "Kim";
    
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == kim){
            answer += to_string(i);
        }
    }
    answer += "에 있다";
    return answer;
}

