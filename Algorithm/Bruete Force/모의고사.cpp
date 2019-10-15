#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int max ( int a, int b){
    return a > b ? a: b;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    int maxScore = 0;
    int size = answers.size();
    int su1[5]  = {1, 2, 3, 4, 5};
    int su2[8] = {2, 1, 2, 3, 2, 4, 2, 5,};
    int su3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    
    for(int i = 0; i < size; i++){
        if(su1[i%5] == answers[i]) score[0]++;
        if(su2[i%8] == answers[i]) score[1]++;
        if(su3[i%10] == answers[i]) score[2]++;
    }
    maxScore = max(max(score[0], score[1]), score[2]);
    for(int i = 0; i < 3; i++)
        if(score[i] == maxScore) answer.push_back(i+1);
    return answer;
}