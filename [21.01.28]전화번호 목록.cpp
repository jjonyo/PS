#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set <string> h;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    vector <pair<int,string>> v;
    for (auto s : phone_book){
        v.push_back({s.size(),s});
    }
    
    sort(v.begin(),v.end());
    
    for (auto cur : v){
        int len = cur.first;
        string str = cur.second;
        string p;
        for (int i=0;i<len;i++){
            p.append(string(1,str[i]));
            if (h.find(p) != h.end()){
                return false;
            }
        }
        h.insert(str);
    }
    
    return answer;
}