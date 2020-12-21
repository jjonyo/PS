/*
    20.09.06
    BOJ : 2457 공주님의 정원 (https://www.acmicpc.net/problem/2457)
    그리디
*/

#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> F;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        F.push_back({ s1 * 100 + s2,e1 * 100 + e2 });
    }

    sort(F.begin(), F.end());

    int date = 301, idx = 0, maxdate = 0;
    int ans = 0;
    while (date <= 1130)
    {
        for (int i = idx; i < N; i++)
        {
            if (F[i].first > date) break;
            if (F[i].second > maxdate)
            {
                maxdate = F[i].second;
                idx = i;
            }
        }

        if (maxdate==date)
        {
            cout << 0;
            return 0;
        }
        else
        {
            date = maxdate;
            ans++;
        }
    }
    cout << ans;
        
}
