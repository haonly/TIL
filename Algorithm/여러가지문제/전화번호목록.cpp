#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    for(string s1 : phone_book) {
        map<string, int> m;
        int size = s1.length();
        
        for(string s2 : phone_book){
            if(s2.length() < size) continue; 
            string cut_num = s2.substr(0,size);
            if(s1.compare(cut_num)==0){ 
                m[cut_num]++;
            }
        }
        map<string, int>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if(iter->second > 1) {
                return false;
            }
        }
    }
    return true;
}