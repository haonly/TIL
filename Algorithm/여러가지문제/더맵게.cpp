#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    int answer = 0;
    
    for(int i = 0; i < scoville.size(); i++){
        PQ.push(scoville[i]);
    }
    
    int first, second;
    
    while(PQ.top() < K){
        if(PQ.size() <= 1)
            return -1;
        first = PQ.top();
        PQ.pop();
        second = PQ.top();
        PQ.pop();
        first = first + second*2;
        PQ.push(first);
        answer++;
    }
    return answer;
}