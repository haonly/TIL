#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size=commands.size();

   for(int i = 0; i < size; i++){ 
       vector<int> tmp_arr(&array[commands[i][0]-1], &array[commands[i][1]]);
       sort(tmp_arr.begin(), tmp_arr.end());
       answer.push_back(tmp_arr[commands[i][2]-1]);
   }
    return answer;
}