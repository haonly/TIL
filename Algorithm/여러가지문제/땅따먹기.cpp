#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_max(int a, int b, int c, int d){
    int max1, max2;
    if(a > b)
        max1 = a;
    else
        max1 = b;
    if(c > d)
        max2 = c;
    else
        max2 = d;
    return (max1 > max2) ? max1 : max2;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int size = land.size();
    
    for(int i = 0; i < size-1; i++){
        land[i+1][0] += get_max(land[i][1], land[i][2], land[i][3], 0);
        land[i+1][1] += get_max(land[i][0], land[i][2], land[i][3], 0);
        land[i+1][2] += get_max(land[i][0], land[i][1], land[i][3], 0);
        land[i+1][3] += get_max(land[i][0], land[i][1], land[i][2], 0);
    }
    
    answer = get_max(land[size-1][0], land[size-1][1], land[size-1][2], land[size-1][3]);
    
    return answer;
}