#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    if(len == 4 or len == 6){
        for(int i = 0; i < len; i++){
            if(isdigit(s[i]) == 0)
                return false;
        }
    }
    else
        return false;
    return answer;
}