/*
    2022.05.06
    PGM : k진수에서 소수 개수 구하기 (https://programmers.co.kr/learn/courses/30/lessons/92335)
    Algorithm : 구현
*/

class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        
        String num = Integer.toString(n, k);
        String[] split = num.split("0");

        for (String s : split) {
            if (s.isEmpty()) continue;
            if(isPrime(Long.parseLong(s))) {
                answer++;
            }
            System.out.println(s);
        }
        
        return answer;
    }
    
    public boolean isPrime(long N){
	
	if( N == 1 ) return false;
	else if( N == 2 ) return true;
	else if( N % 2 == 0 ) return false;
		
	int count = 0;
	for(int i = 3; i <= Math.sqrt(N); i += 2){
		if( N % i == 0 ){
			count++;
			break;
		}
	}
	return count == 0;
}
}