#include <string>
#include <vector>

using namespace std;
int vis[201] = {0};

int nn;
void dfs(int cur,vector<vector<int>>& computers){
    vis[cur] = 1;
    
    for (int i=0;i<nn;i++){
        if (vis[i] == 1) continue;
        if (computers[cur][i] == 0) continue;
        dfs(i,computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    nn=n;
    for (int i=0;i<n;i++){
        if (vis[i] == 0){
            answer++;
            dfs(i,computers);
        }
    }
    
    return answer;
}