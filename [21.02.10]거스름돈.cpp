#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define div 1000000007

int dp[110][100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    int size = money.size();
    
    for (int i=1;i<=size;i++){
        dp[i][0] = 1;
    }
    
    
    
    for (int i=0;i<size;i++){
        for (int j=1;j<=n;j++){
            dp[i+1][j] = dp[i][j] % div;
            if (j >= money[i])
                dp[i+1][j] += (dp[i+1][j - money[i]]) % div;
        }
    }
    answer = dp[size][n];
    
    return answer;
}