#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int size1, size2;    
    double hap = 0, con = 0;
    map<string, int> map1;
    
    for(int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);
    for(int i = 0; i < str2.length(); i++)
        str2[i] = tolower(str2[i]);
    size1 = str1.size();
    size2 = str2.size();
    
    for(int i = 0; i < size1-1; i++){
        if(str1[i] < 97 || str1[i] > 122) continue;
        if(str1[i+1] < 97 || str1[i] > 122) continue;
        string tmp = "";
        tmp += str1[i];
        tmp += str1[i+1];
        hap++;
        if(map1.count(tmp))
            map1[tmp]++;
        else
            map1[tmp] = 1;
    }
    for(int i = 0; i < size2-1; i++){
        if(str2[i] < 97 || str2[i] > 122) continue;
        if(str2[i+1] < 97 || str2[i] > 122) continue;
        string tmp = "";
        tmp += str2[i];
        tmp += str2[i+1];
        if(map1.count(tmp)){
            if(map1[tmp] > 0){
                map1[tmp]--;
                con++;
            }
            else hap++;
        }
        else
            hap++;
    }
    if(hap != 0){
        answer = 65536;
        answer = (int)((double)answer * (con/hap));
        return answer;
    }
    if(hap == 0 || con == 0)
        return 65536;
}