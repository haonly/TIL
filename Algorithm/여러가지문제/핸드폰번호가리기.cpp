#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length();
    cout << len << endl;
    for(int i = 0; i < len-4; i++){
        answer += "*";
    }
    answer += phone_number.substr(len-4, len);
    cout << answer;
    return answer;
}