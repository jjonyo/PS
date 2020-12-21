/*
    20.09.01
    BOJ : 10164 r격자상의 경로 (https://www.acmicpc.net/problem/10164)
    다이나믹 프로그래밍
*/

#include <bits/stdc++.h>
using namespace std;

int arr[16][16];
int dp[16][16];
pair <int, int> pass;
int N, M, K;

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int dfs(int r, int c, int vis)
{
    if (r == N && c == M && vis == 1) return 1;
    if (dp[r][c] != -1) return dp[r][c];
    if (r == pass.first && c == pass.second) vis = 1;

    dp[r][c] = 0;
    for (int dir = 0; dir < 2; dir++)
    {
        int nx = r + dx[dir];
        int ny = c + dy[dir];
        if (nx<1 || nx>N || ny<1 || ny>M) continue;
        if (vis == 0 && nx > pass.first) continue;
        if (vis == 0 && ny > pass.second) continue;
        dp[r][c] += dfs(nx, ny, vis);
    }

    return dp[r][c];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N>>M>>K;
    int num = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (num == K) pass = { i,j };
            arr[i][j] = num++;
            dp[i][j] = -1;
           
        }
    }
    if (K == 0)
        cout << dfs(1, 1, 1);
    else
        cout << dfs(1, 1, 0);
    


}
