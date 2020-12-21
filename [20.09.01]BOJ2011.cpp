/*
    20.09.01
    BOJ : 2011 암호코드 (https://www.acmicpc.net/problem/2011)
    다이나믹 프로그래밍
*/

#include <bits/stdc++.h>
#define D 1000000
using namespace std;

int dp[5001];
string str;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    int len = str.length();
    dp[0] = 1;
    dp[1] = 1;

    if (str[0] - '0' == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= len; i++)
    {
        if (str[i-1]-'0' > 0)
            dp[i] = dp[i - 1] % D;

        int cmp = stoi(str.substr(i - 2, 2));
        if (cmp >= 10 && cmp <= 26)
            dp[i] =(dp[i]+ dp[i - 2])%D;
    }
    
    cout << dp[len];
    
    return 0;
}
