#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> w) {
    int answer, sum = 0;
    sort(w.begin(), w.end());
    for(int i = 0; i < w.size(); i++){
        if (sum + 1 >= w[i])
            sum = sum + w[i];
        else
            break;
    }  
    return answer = sum + 1;
}