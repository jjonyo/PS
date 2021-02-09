#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct info {
	int play = 0;
	int index = 0;
};


map <string, int> music;
pair<int,int> sum[101];
vector <info> list[101];

bool cmp1(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}

bool cmp2(info a, info b){
    if (a.play == b.play){
        return a.index < b.index;
    }else{
        return a.play > b.play;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int size = plays.size();
    
    int cnt=1;
    for (int i=0; i < size; i++){
        string cur = genres[i];
        int idx = music[cur];
        
        if (idx == 0){
            music[cur] = cnt++;
            idx = music[cur];
        }
        
        list[idx].push_back({plays[i],i});
        sum[idx].first += plays[i];
        sum[idx].second = idx;
    }
    
    sort(sum,sum+cnt+1,cmp1);
    
    for (int i=0;i<cnt-1;i++){
        int idx = sum[i].second;
        sort(list[idx].begin(),list[idx].end(),cmp2);
        
        if (list[idx].size() <2){
            answer.push_back(list[idx][0].index);
        }else{
            answer.push_back(list[idx][0].index);
            answer.push_back(list[idx][1].index);
        }
        
    }

    return answer;
}