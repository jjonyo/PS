#include <string>
#include <vector>

using namespace std;

int calc(int n){
    if (n == 1) return 0;
    else if (n < 10) return 1;
    else if (n < 100) return 2;
    else if (n < 1000) return 3;
    else if (n==1000) return 4;
}

int solution(string s) {
    int answer = 2000000000;

    int len = s.size();
    for (int i = 1; i <= len / 2; i++) { //substr 개수
        int idx = 0;
        int res = 0;

        while (true) {
            if (idx + i >= len) {
                res += len - idx;
                break;
            }
            string str = s.substr(idx, i);
            int cnt = 1;
            int j;
            for (j = idx + i; j < len; j += i) {
                string cStr = s.substr(j, i);
                if (str == cStr) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            idx = j;
            res += (calc(cnt) + i);
        }

        answer = min(answer, res);
    }
    if (answer == 2000000000) answer=1;
    return answer;
}