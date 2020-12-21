/*
    20.09.01
    BOJ : 2096 내려가기 (https://www.acmicpc.net/problem/2096)
    다이나믹 프로그래밍
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int maxdp[3][3];
int mindp[3][3];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < 3; i++)
    {
        int val;
        cin >> val;
        maxdp[1][i] = val;
        mindp[1][i] = val;
    }

    if (N == 1)
    {
        cout << max({ maxdp[1][0], maxdp[1][1], maxdp[1][2] }) << ' ' << min({ mindp[1][0], mindp[1][1], mindp[1][2] });
        return 0;
    }

    
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int val;
            cin >> val;
            if (j == 0)
            {
                maxdp[2][j] = val + max(maxdp[1][j], maxdp[1][j + 1]);
                mindp[2][j] = val + min(mindp[1][j], mindp[1][j + 1]);
            }
            else if (j == 1)
            {
                maxdp[2][j] = val + max({ maxdp[1][j - 1],maxdp[1][j], maxdp[1][j + 1] });
                mindp[2][j] = val + min({ mindp[1][j - 1],mindp[1][j], mindp[1][j + 1] });
            }
            else if (j == 2)
            {
                maxdp[2][j] = val + max(maxdp[1][j], maxdp[1][j - 1] );
                mindp[2][j] = val + min(mindp[1][j], mindp[1][j - 1]);
            }
        }
        for (int j = 0; j <= 2; j++)
        {
            maxdp[1][j] = maxdp[2][j];
            mindp[1][j] = mindp[2][j];
        }
    }


     int maxans = max({ maxdp[2][0],maxdp[2][1],maxdp[2][2] });
     int minans = min({ mindp[2][0],mindp[2][1],mindp[2][2] });
    
    cout << maxans << ' ' << minans;
    
    return 0;
}
