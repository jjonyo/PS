#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <string,int> cnt[11];

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto order : orders) {
        sort(order.begin(),order.end());
        for (int i = 1; i < (1 << order.size()); i++) {       
            string menu;
            for (int j = 0; j < order.size(); j++) {
                if (i & (1 << j)) {
                    menu += order[j];
                }
            }
            if (menu.size() < 2)continue;
            cnt[menu.size()][menu]++;
        }
    }

    for (int co : course) {
        int mx = 0;
        for (auto cur : cnt[co]) {
            mx = max(mx, cur.second);
        }
        if (mx<2) continue;
        for (auto cur : cnt[co]) {
            if (cur.second == mx) {
                answer.push_back(cur.first);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}