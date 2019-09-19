#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> map;
    vector<string> tockens;
    int interaction = record.size();
    
    for(int i = 0; i < interaction; i++){
        string buf;
        stringstream ss(record[i]);
        while(ss >> buf){
            tockens.push_back(buf);
        }
        if(tockens[0] == "Enter"){
            if(map.find(tockens[1]) == map.end()){
                map.insert(pair<string, string>(tockens[1], tockens[2]));
            }
            else
                map[tockens[1]] = tockens[2];
        }
        else if(tockens[0] == "Leave"){
        }
        else if(tockens[0] == "Change"){
            map[tockens[1]] = tockens[2];
        }
        tockens.clear();
    }
        
    
   for(int i = 0; i < interaction; i++){
        string buf;
        stringstream ss(record[i]);
        while(ss >> buf){
            tockens.push_back(buf);
        }
        for(int j = 0; j < tockens.size(); j++){
            if(tockens[j] == "Enter"){
                answer.push_back(map.at(tockens[j+1]) + "님이 들어왔습니다.");
            }
            if(tockens[j] == "Leave"){
                answer.push_back(map.at(tockens[j+1]) + "님이 나갔습니다.");
            }
        }
        tockens.clear();
    }
    
    return answer;
}