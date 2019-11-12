// 1700 멀티탭스케줄링(그리디)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    // multiTap[i]: i번 구에 꽂혀있는 전기용품의 번호
    // plan[i]: i번째로 사용할 전기용품의 번호
    int N, K, multiTap[100] = {0}, plan[100];
    cin >> N >> K;
    for(int i=0; i<K; i++)
        cin >> plan[i];
 
    int result = 0;
    for(int i=0; i<K; i++){
        // 먼저 해당 전기용품이 이미 꽂혀 있는지 확인
        bool inTap = false;
        for(int j=0; j<N; j++)
            if(plan[i] == multiTap[j]){
                inTap = true;
                break;
            }
        // 이미 꽂혀 있다면 아무것도 뽑을 필요 없음
        if(inTap) continue;
 
        // 아직 비어 있는 구멍이 있는지 확인
        inTap = false;
        for(int j=0; j<N; j++)
            if(multiTap[j] == 0){
                // 비어 있는 구멍을 발견하면 거기에 꽂음
                multiTap[j] = plan[i];
                inTap = true;
                break;
            }
        // 비어 있는 구멍이 있다면 아무것도 뽑을 필요 없음
        if(inTap) continue;
 
        // 가장 나중에 다시 사용될 전기용품을 찾음
        int swap, val = -1;
        for(int j=0; j<N; j++){
            int term = 0;
            for(int k=i+1; k<K && multiTap[j]!=plan[k]; k++) term++;
            if(term > val){
                swap = j;
                val = term;
            }
        }
        // 플러그를 뽑는 횟수 1 증가
        result++;
        // 해당 구멍에 꽂혀 있는 전기용품이 바뀜
        multiTap[swap] = plan[i];
    }
    cout << result;
}