#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//
    int test_case;
    int T;
    cin>>T;

    string nums;
    int size = 0;
    string notes = "";
    for(test_case = 1; test_case <= T; ++test_case){

        cin >> nums;
        size = nums.size();
        for(int i = 0; i < size; i++){

            if(notes.find(nums[i]) == -1){
                notes += nums[i];
            }
            else
                notes.erase(notes.find(nums[i]), 1);
        }
        cout <<"#";
        cout <<test_case;
        cout << " ";
        cout << notes.size() << endl;
        notes.clear();

    }
    return 0;
}
