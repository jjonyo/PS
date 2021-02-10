#include <string>
#include <vector>
using namespace std;

vector <string> list;

bool isSame(string a,string b){
    if (a.size() != b.size() ) return false;
    int len = a.size();
    
    for (int i=0;i<len;i++){
        if(toupper(a[i]) != toupper(b[i]))
            return false;
    }
    
    return true;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    int size = cities.size();
    
    if (cacheSize == 0){
        return 5 * cities.size();
    }
    
    for (int i=0; i < size; i++){
        string cur = cities[i];
        
        bool check=false;
        for (int j=0;j<list.size();j++){
            if (isSame(list[j],cur)){ //HIT
                answer += 1;
                list.erase(list.begin() + j);
                list.push_back(cur);
                check=true;
                break;
            }
        }
        
        if(!check){ //MISS
            answer += 5;
            if (list.size() >= cacheSize){ //LRU
                list.erase(list.begin());
                list.push_back(cur);
            }else{
                list.push_back(cur);
            }
        }
        
    }

    return answer;
}
