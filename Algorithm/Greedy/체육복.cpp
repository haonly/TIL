#include <string>
#include <vector>
#include <iostream>

using namespace std;

 struct Sets{
    int student;
    int has;
};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_num = 0;
    
    Sets sets[n];
    sets[0].student = 31;
    sets[0].has = 31;
    sets[n+1].student=31;
    sets[n+1].has = 31;
    for(int i = 1; i <= n; i++){
        sets[i].student = i;
        sets[i].has = 1;
    }
    for(int i = 0; i < reserve.size(); i++)
        sets[reserve[i]].has++;
    for(int i = 0; i < lost.size();i++)
        sets[lost[i]].has--;
    
    for(int i = 1; i <= n;i++){
        if(sets[i].has == 0 && sets[i+1].has == 2){
            sets[i].has++;
            sets[i+1].has--;
        }
        if(sets[i].has==0 && sets[i-1].has == 2){
            sets[i].has++;
            sets[i-1].has--;
        }
    }
    
    
    for(int i =1; i <= n; i++){
        if(sets[i].has >= 1)
            answer++;
    }
    for(int i = 1; i <= n; i++)
        cout << sets[i].student << sets[i].has << endl;
  
    cout << answer;
    return answer;
}