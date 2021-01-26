#include <string>
#include <vector>

using namespace std;

string go(int n){
    if (n == 1) return "1";
    else if (n==2) return "2";
    else if (n==3) return "4";
    else{
        int t = (n/3);
        if (n%3 == 0) t-=1;
        string add;
        if (n%3 == 0){
            add = "4";
        }else if (n%3 == 1){
            add = "1";
        }else if (n%3 == 2){
            add = "2";
        }
        
        string ret = go(t) + add;
        return ret;
    }
}

string solution(int n) {
    string answer = "";
    answer = go(n);
    return answer;
}