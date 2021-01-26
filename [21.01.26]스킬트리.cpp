#include <string>
#include <vector>
#include <string.h>

using namespace std;
int check[26]={0};
int order[26]={0};

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int len = skill.size();
    
    for (int i=0;i<26;i++){
        order[i] = -1;
    }
    
    for (int i=0; i<len; i++){
        order[skill[i] - 'A'] = i;
    }
    
    for (int i=0;i<skill_trees.size();i++){
        memset(check,0x00,sizeof(check));
        int valid=true;
        int size = skill_trees[i].size();      
        for (int j=0;j<size;j++){
            int o = order[skill_trees[i][j] - 'A'];
            if (o == -1) continue;
            
            int c = true;
            for (int k=0;k<o;k++){
                if (check[k] == 0)
                {
                    c = false;
                    break;
                }
            }
            
            if(!c){
                valid=false;
                break;
            }
            else{
                check[o]=1;
            }
        }
        
        if(valid) answer++;
    }
    return answer;
}