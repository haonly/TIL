#include <string>
#include <vector>

using namespace std;
int isOdd(long long num){
    return num % 2 == 0 ? 1 : 2;
}
int solution(int num) {
    long long num_ = num;
    int answer = -1;
    for(int i = 0; i < 500; i++){
        if(num_ == 1)
            return i;
        if(isOdd(num_) == 1)
            num_ /= 2;
        else
            num_ = num_ * 3 + 1; 
    }
    return answer;
}