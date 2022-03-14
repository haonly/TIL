#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> idx_map;
    for(int i = 0; i < id_list.size(); ++i) idx_map[id_list[i]] = i;
    

    unordered_map<string, set<string>> reported_map;
    stringstream ss;
    for(auto rep: report) {
        ss.str(rep);
        string reporter, reportee;
        ss >> reporter >> reportee; //문자열 parsing
        //신고 정보 저장
        reported_map[reportee].insert(reporter);
        ss.clear();
    }
    
    for(auto it: reported_map) {
        if(it.second.size() >= k) { //어떤 멤버를 신고한 사람이 k명 이상이면
            for(auto set_it: it.second) { //신고한 사람들의 count 증가
                int idx = idx_map[set_it];
                answer[idx]++;
            }   
        }
    }
    
    return answer;
}