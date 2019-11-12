#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    
    sort(people.begin(), people.end());
    int i = 0, j = 0;
    
    for(j = size-1; j > i; j--){
        if(people[j] + people[i] <= limit){
            i++;
            answer++;
        }
        else
            answer++;
    }
    if(i == j)
        answer++;
    return answer;
}