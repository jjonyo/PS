#include <string>
#include <vector>
#include <queue>

using namespace std;

int check(string& a,string& b){
    int len = a.size();
    int ret=0;
    for (int i=0;i<len;i++){
        if (a[i] != b[i])
            ret++;
    }
    
    return ret;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int len = words.size();
    queue <pair<string,int>> q;
    
    q.push({begin,0});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(cur.first == target){
            return cur.second;
        }
        
        if (cur.second > len){
            return 0;
        }
        
        for (int i=0;i<words.size();i++){
            if (check(cur.first,words[i]) == 1){
                q.push({words[i],cur.second+1});   
            }
        }
    }
    
    return answer;
}