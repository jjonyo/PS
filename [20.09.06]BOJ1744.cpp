/*
    20.09.06
    BOJ : 1744 수 묶기 (https://www.acmicpc.net/problem/1744)
    그리디
*/
#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> m_pq;
    priority_queue<int, vector<int>, less<int>> p_pq;
    int zerocount = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            p_pq.push(temp);
        }
        else if (temp < 0)
        {
            m_pq.push(temp);
        }
        else
        {
            zerocount++;
        }
    }

    int ans = 0;
    while (m_pq.size() >= 2)
    {
        int a, b;
        a = m_pq.top(); m_pq.pop();
        b = m_pq.top(); m_pq.pop();
        ans += a * b;
    }

    while (p_pq.size() >= 2 && p_pq.top()!=1)
    {
        int a, b;
        a = p_pq.top(); p_pq.pop();
        b = p_pq.top(); p_pq.pop();
        if (a == 1 || b == 1) ans += a + b;
        else ans += a * b;
    }

    while (zerocount>0)
    {
        if (!m_pq.empty())
        {
            int temp = m_pq.top(); m_pq.pop();
            zerocount--;
        }
        else
            break;
    }
    
    while (!m_pq.empty())
    {
        ans += m_pq.top(); m_pq.pop();
    }
    while (!p_pq.empty())
    {
        ans += p_pq.top(); p_pq.pop();
    }

    cout << ans;
    
}
