#include <string>
#include <vector>
#include <queue>

using namespace std;
struct info{
    int w;
    int t;
};

queue <info> ing;
int ingWeight=0;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur=0;
    int size = truck_weights.size();
    
    ing.push({truck_weights[0],0});
    ingWeight += truck_weights[0];
    answer++;
    cur++;
    
    while(!ing.empty()){
        
        auto first = ing.front();
        if (answer - first.t >= bridge_length){
            ingWeight -= first.w;
            ing.pop();
        }
        
        if (cur < size){
            if (truck_weights[cur] + ingWeight <= weight){ //견딜 수 있음
                ingWeight += truck_weights[cur];
                ing.push({truck_weights[cur],answer});
                cur++;
            }
        }
        
        answer++;
    }
    
    return answer;
}