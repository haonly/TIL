import java.util.*;
class Solution {
    
    public ArrayList<Integer> solution(int[] arr, int divisor) {
        int[] answer = {};
        ArrayList<Integer> ansList = new ArrayList<Integer>();
        
        Arrays.sort(arr);
        
        for(int i = 0; i < arr.length; i++){
            if(arr[i] % divisor == 0){
                ansList.add(arr[i]);
            }    
        }
        if(ansList.size() == 0){
            ansList.add(-1);
        }
        return ansList;
    }
}