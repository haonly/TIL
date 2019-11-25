#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int hap = 0;
    
    
    for(int i = 0; i < d.size(); i++){
        hap += d[i];
        if(hap > budget)
            return i;
    }
    return d.size();
}