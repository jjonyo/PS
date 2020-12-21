/*
    20.09.09
    BOJ : 1202 보석 도둑 (https://www.acmicpc.net/problem/1202)
    그리디
*/
#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> price;
vector <int> bag;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;
        price.push_back({ M,V });
    }
   
    for (int i = 0; i < K; i++)
    {
        int input;
        cin >> input;
        bag.push_back(input);
    }

    sort(price.begin(), price.end());
    sort(bag.begin(), bag.end());

    priority_queue <int, vector<int>, less<int>> pq;
    long long int ans = 0;
    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        int cur = bag[i];
        while (idx < N)
        {
            if (price[idx].first > cur) break;
            pq.push(price[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans;
}
