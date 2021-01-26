#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int p_size = progresses.size();
    int s_size = speeds.size();
    
    queue <int> q;
    
    for (int i=0;i<p_size;i++){
        q.push(progresses[i]);
    }
    
    int i=0;
    while(!q.empty()){
        int top = q.front();
        
        int day = (100 - top);
        if (day % speeds[i] == 0){
            day = day / speeds[i];
        }else{
            day = day / speeds[i] + 1;
        }
        i++;
        
        int cnt=1;
        q.pop();
        
        while(!q.empty()){
            int n = q.front() + speeds[i] * day;
            if (n < 100) break;
            q.pop();
            i++;
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}