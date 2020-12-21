/*
    20.09.01
    BOJ : 14226 이모티콘 (https://www.acmicpc.net/problem/14226)
    BFS
*/
#include <bits/stdc++.h>
using namespace std;


typedef struct data
{
    int m;
    int clip;
    int cnt;
}Data;

int vis[1001][1001];
int clip;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S;
    cin >> S;
    queue <Data> Q;
    Data start = { 1,0,0 };
    Q.push(start);
    vis[1][0] = 1;
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        if (cur.m == S)
        {
            cout << cur.cnt;
            return 0;
        }
        Data temp;
        for (int i=0;i<3;i++)
        {
            if (i == 0) //복사
            {           
                temp.m = cur.m;
                temp.clip = cur.m;
                temp.cnt = cur.cnt+1;
                if (vis[temp.m][temp.clip]) continue;
                vis[temp.m][temp.clip] = 1;
                Q.push(temp);
            }
            else if (i == 1) //붙여넣기
            {
                if (cur.clip < 1) continue;
                temp.m = cur.clip+cur.m;
                temp.clip = cur.clip;
                temp.cnt = cur.cnt + 1;
                if (temp.m>1000 || vis[temp.m][temp.clip]) continue;
                vis[temp.m][temp.clip] = 1;
                Q.push(temp);
            }
            else if (i == 2) //삭제
            {
                if (cur.m <= 1) continue;
                temp.m = cur.m - 1;
                temp.clip = cur.clip;
                temp.cnt = cur.cnt + 1;
                if (vis[temp.m][temp.clip]) continue;
                vis[temp.m][temp.clip] = 1;
                Q.push(temp);
            }
        }
    }

   
}
