#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> arr =  {4, 1, 2};
    int a;
    while(n > 0){
        a = n % 3;
        n = n / 3;
        if(a == 0)
            n -= 1;
        answer.insert(0, to_string(arr[a]));
    }
    return answer;
}