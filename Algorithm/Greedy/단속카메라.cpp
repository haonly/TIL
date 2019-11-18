#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int tmp = routes[0][1];
    for(int i = 0; i < routes.size()-1; i++){
        if(tmp > routes[i][1])
            tmp = routes[i][1];
        if(tmp < routes[i+1][0]){
            answer++;
            tmp = routes[i+1][1];
        }
            
    }
    return answer;
}