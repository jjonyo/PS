#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

map <string,string> info;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> db[100001];
    int cnt=0;
    for (int i=0;i<record.size();i++){
        vector <string> query;
        stringstream ss(record[i]);
        string buff;
        while(getline(ss,buff,' ')){
            query.push_back(buff);
        }
        
        if (query[0] == "Enter" || query[0] == "Change"){
            info[query[1]] = query[2];
        }   
        
        if (query[0] != "Change"){
            db[cnt].push_back(query[0]);
            db[cnt].push_back(query[1]);
            cnt++;
        }
    }
    
    for (int i=0;i<cnt;i++){
        string el = db[i][0];
        string id = db[i][1];
        string name = info[id];
        if (el == "Enter"){
            answer.push_back(name + "님이 들어왔습니다.");
        }else if (el == "Leave"){
            answer.push_back(name + "님이 나갔습니다.");
        }
    }
    
    return answer;
}