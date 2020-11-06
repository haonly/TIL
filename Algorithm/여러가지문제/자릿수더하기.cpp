#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string numString = to_string(n);
    for(int i = 0; i < numString.size(); i++){
        answer += numString[i] - '0';
    }

    return answer;
}