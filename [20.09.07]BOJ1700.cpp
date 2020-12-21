/*
    20.09.07
    BOJ : 1700 멀티탭 스케쥴링 (https://www.acmicpc.net/problem/1700)
    그리디
*/
#include <bits/stdc++.h>
using namespace std;

int isUsed[101];
int task[101];

vector <int> plug;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin >> N >> K;
    


    for (int i = 0; i < K; i++)
    {
        cin >> task[i];
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < K; i++)
    {
        int input = task[i];

        if (isUsed[input]) continue; //이미 콘센트에 꽂혀있다면 그냥 넘어간다.
        else
        {
            if (cnt != N) //콘센트에 빈 자리가 있다면 먼저 채운다.
            {
                 isUsed[input] = true;
                 plug.push_back(input);
                 cnt++;
                 continue;
            }
        } 

        //기존에 꽂혀있던 걸 뽑고 새로운걸 꼽아야 함 꽂혀 있는 콘센트 중 가장 나중에 사용되는 콘센트를 뽑아야 한다.
        int idx = 0,lastcnt=0;
        for (int j = 0; j < N; j++)
        {
            int count = 0;
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == task[k]) break;
                count++;
            }
            if (count > lastcnt)
            {
                idx = j;
                lastcnt = count;
            }
        }
        isUsed[plug[idx]] = 0;
        plug[idx] = input;  
        isUsed[input] = 1;
        ans++;
    }
    cout << ans;
    
}
