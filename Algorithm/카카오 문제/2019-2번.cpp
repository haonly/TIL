#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stage_person(N+2);
    vector<int> staged_person(N+2);
    map<int, float> ratio;
    
    for(int input: stages){
        for(int i = N+1; i > 0; i--){
            if(input == i)
                stage_person[i]++;
            if(input >= i)
                staged_person[i]++;
        }
    }

    for(int i = 1; i < N+1; i++){
         if(stage_person[i] == 0 ){
            ratio[i] = 0;
            continue;
        }
        else
            ratio[i] = (float)stage_person[i] / (float)staged_person[i];
    }
    
    vector<pair<int, double>> v(ratio.begin(), ratio.end());
	sort(v.begin(), v.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
		return a.second != b.second ? a.second > b.second : b.first > a.first;
	});
    
    for(auto &p: v)
		answer.push_back(p.first);
    
    return answer;
}