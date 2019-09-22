#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int total_day = 0;
    int index;
    string str_day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month_day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i = 0; i < a-1; i++){
        total_day += month_day[i];
    }
    total_day += b-1;
    index = (5 + total_day) % 7;
    answer = str_day[index];
    return answer;
}