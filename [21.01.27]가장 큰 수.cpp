#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b){
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector <string> list;
    
    int len = numbers.size();
    
    for (auto i : numbers){
        list.push_back(to_string(i));
    }
    
    sort(list.begin(),list.end(),cmp);
    
    for (auto s : list){
        answer.append(s);
    }
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}