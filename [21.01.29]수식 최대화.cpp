#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// + : 0, - : 1, * : 2
// 우선순위 1,2,3 

int p[3] = { 2,1,3 };
stack <long long> num;
stack <char> op;

int getPriority(char op) {
    if (op == '+') return p[0];
    else if (op == '-') return p[1];
    else if (op == '*') return p[2];
}

long long solution(string exp) {
    long long answer = 0;

    do {
        int len = exp.size();
        string s;
        for (int i = 0; i <= len; i++) {
            if (i == len || exp[i] == '-' || exp[i] == '+' || exp[i] == '*') {
                num.push(stoll(s));
                s.clear();
                if (i == len) break;
                int p = getPriority(exp[i]);
                if (op.empty() || p > getPriority(op.top())) {
                    op.push(exp[i]);
                }
                else {
                    while (!op.empty() && p <= getPriority(op.top())) {
                        long long f = num.top(); num.pop();
                        long long se = num.top(); num.pop();
                        char o = op.top(); op.pop();

                        long long temp;
                        if (o == '+') {
                            temp = se + f;
                        }
                        else if (o == '-') {
                            temp = se - f;
                        }
                        else if (o == '*') {
                            temp = se * f;
                        }

                        num.push(temp);
                    }

                    op.push(exp[i]);
                }
            }
            else {
                s.append(string(1, exp[i]));
            }
        }

        while (!op.empty()) {
            long long f = num.top(); num.pop();
            long long se = num.top(); num.pop();
            char o = op.top(); op.pop();

            long long temp;
            if (o == '+') {
                temp = se + f;
            }
            else if (o == '-') {
                temp = se - f;
            }
            else if (o == '*') {
                temp = se * f;
            }

            num.push(temp);
        }
        answer = max(answer,abs(num.top()));
        num.pop();
        
    } while (next_permutation(p, p + 3));

    return answer;
}
