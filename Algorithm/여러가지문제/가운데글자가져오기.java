class Solution {
    public String solution(String s) {
        String answer = "";
        int len = s.length();
        int loc = 0;
        
        if(len % 2 == 0){
            loc = (len / 2)-1;
            answer += s.charAt(loc);
            answer += s.charAt(loc+1);
        }
        else{
            loc = (len+1) / 2;
            answer += s.charAt(loc-1);
        }
        
        return answer;
    }
}