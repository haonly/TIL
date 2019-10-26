// 1700 멀티탭스케줄링(그리디)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,ans;
vector<int> order;

int multiTap[101];

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        order.push_back(tmp);
    }
    
    ans = 0;
    
    for(int i=0; i<order.size(); i++){
        int item = order[i];
        
        // 콘센트가 이미 꽃혀있는지 확인
        bool hole = false;
        for(int j=1; j<=n; j++){
            if(multiTap[j] == item){
                hole = true;
                break;
            }
        }
        
        // 콘센트가 안꽂혀있다면
        if(!hole){
            // 빈 콘센트가 존재한다면
            bool empty = false;
            for(int j=1; j<=n; j++){
                if(multiTap[j] == 0){
                    multiTap[j] = item;
                    empty = true;
                    break;
                }
            }
            
            // 빈 콘센트가 존재하지 않아 하나를 빼야한다면
            if(!empty){
                int idx = 0;
                int max_value = 0;
                bool reuse = true;
                
                // 멀티탭의 전기용품들을 탐색
                for(int j=1; j<=n; j++){
                    int cnt = 1;
                    bool end = true;
                    
                    for(int l=i; l<order.size(); l++,cnt++){
                        if(multiTap[j] == order[l]){
                            if(cnt > max_value){
                                max_value = cnt;
                                idx = j;
                            }
                            
                            // 해당 전기용품은 추후에 재사용됨
                            end = false;
                            break;
                        }
                    }
                    
                    // 멀티텝의 물건들이 추후에 사용되지 않는 경우
                    if(end){
                        multiTap[j] = item;
                        ans++;
                        reuse = false;
                        break;
                    }
                }
                
                // 멀티탭의 물건들이 추후에 전부 사용되는 경우
                if(reuse){
                    multiTap[idx] = item;
                    ans++;
                }
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
