//10610 30(그리디)

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

#define DECI 10
#define N_MAX 100000+1
int number_vec[DECI] = { 0 };
int main(int argc, const char * argv[]) {
    
     char N_arr[N_MAX];
       scanf("%s", N_arr);
       int N_len = strlen(N_arr);

       // 수 세기
       for ( int N_idx = 0 ; N_idx < N_len ; N_idx++){
           int now_num = N_arr[N_idx] - '0';
           number_vec[now_num] += 1;
       }

       // 0이 없으면 그냥 -1 출력
       // 아니면 0 하나 감소
       if(number_vec[0] == 0) {
           printf("-1"); return 0;
       }else{
           number_vec[0] -= 1;
       }

       // 전체 합 구해보자
       int now_sum = 0 ;
       for ( int num_idx = 1 ; num_idx < DECI ; num_idx++){
           now_sum += number_vec[num_idx]*num_idx;
       }

       switch(now_sum % 3){
           case 0:
               break;
           default:
               printf("-1"); return 0;
               break;
       }

       // 남은 수를 가지고 최대 수를 출력
       for (int resi_idx = DECI -1 ; resi_idx >= 0 ; resi_idx-- ) {
           while(number_vec[resi_idx]){
               printf("%d" , resi_idx);
               number_vec[resi_idx]--;
           }
       }
       printf("0");

       return 0;
}
