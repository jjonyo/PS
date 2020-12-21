/*
20.09.14 코딩부트 캠프 연습문제
LEVEL 2 문자열 디코딩
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*
example input
2[abc]3[cd]ef
3[a2[c]]
*/

int main(void) {

    string input;
    cin >> input;

    int len = input.size();
    stack <char> s;
    for (int i = 0; i < len; i++)
    {
        char check=input[i];

        if (check == ']')
        {
            string temp="";
            while (s.top() != '[')
            {
                temp += s.top();
                s.pop();
            }
            s.pop();

            int count = s.top() - '0'; s.pop();
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < count; i++)
            {
                int size = temp.size();
                for (int i = 0; i < size; i++)
                    s.push(temp[i]);
            }
        }
        else
        {
            s.push(input[i]);
        }
    }

    string ans = "";
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
