#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool isPrime[10000000];
bool check[10000000];

int solution(string numbers) {
    int answer = 0;
    
    memset(isPrime,true,sizeof(isPrime));
    
    isPrime[0] = 0;
    isPrime[1] = 0;
    //소수 판별
    for (int i=2;i<=10000000;i++){
        if (!isPrime[i]) continue;
        
        for (int j=2*i;j<=10000000;j+=i){
            isPrime[j] = 0;
        }
    }
    
    sort(numbers.begin(),numbers.end());
    
    do{
        int len = numbers.size();
        string str;
        for (int i=0;i<len;i++){
            str.append(string(1,numbers[i]));
            
            int num = stoi(str);
            if (check[num]) continue;            
            if (isPrime[num]){
                answer++;
                check[num]=1;
            }
        }
      
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    
    return answer;
}