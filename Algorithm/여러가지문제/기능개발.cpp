#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(progresses.size());
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        while( !(progresses[i] >= 100)){   
           progresses[i] += speeds[i];
           days[i]++;
       }
    }
    for(int i = 0; i < days.size(); i++){
        q.push(days[i]);
    }
    
    int cnt = 1;
    int curr = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= curr) {
            q.pop();
            cnt++;
        }
        else {
            answer.push_back(cnt);
            cnt = 1;
            curr = q.front();
            q.pop();
        }
    }
    answer.push_back(cnt);

    return answer;
}