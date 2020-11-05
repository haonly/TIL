#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

string solution(string s) {
    string answer = "";
    vector<string> nums = split(s, ' ');
    vector<int> num;
    int max = -9874;
    int min = 9874;

    for(int i= 0; i < nums.size(); i++){
        num.push_back(atoi(nums[i].c_str()));
        if(num[i] > max)
            max = num[i];
        if(num[i] < min)
            min = num[i];
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}