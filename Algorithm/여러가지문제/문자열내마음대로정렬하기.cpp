#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
bool comp (string a, string b) {
    if(a.at(N) != b.at(N)){
        return a.at(N) < b.at(N);
    }else{
        return a< b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}