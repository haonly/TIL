#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> q;
    
    for(int i = 0; i < truck_weights.size(); i++){
        int current = truck_weights[i];
        
        while(true){
            if(q.empty()){
                q.push(current);
                answer++;
                sum += current;
                break;
            }
            else if(q.size() == bridge_length){
                sum -= q.front();
                q.pop();
            }
            else{
                if(sum + current > weight){
                    q.push(0);
                    answer++;
                }
                else{
                    q.push(current);
                    answer++;
                    sum += current;
                    break;
                }
            }
        }
    }

    return answer + bridge_length;
}