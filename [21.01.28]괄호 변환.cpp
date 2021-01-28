#include <string>
#include <vector>
#include <stack>
using namespace std;

int isValid(string p){
    stack <int> st;
    int len = p.size();
    for (int i=0;i < len;i++){
        if (p[i] == '('){
            st.push(1);
        }else if (p[i] == ')'){
            if (st.empty()){
                return 0;
            }else{
                st.pop();
            }
        }
    }
    return 1;
}

void reverse(string& p){
    int len = p.size();
    for (int i=0;i<len;i++){
        if (p[i] == '('){
            p[i] =')';
        }else{
            p[i] = '(';
        }
    }
}

string go(string p){
    if (p=="") return "";
    
    string u="",v="";
    
    int c=0;
    int i=0;
    for (i=0;i<p.size();i++){
        if (p[i]=='(') c--;
        else c++;
        
        if (c == 0) break;
    }
    
    u = p.substr(0,i+1);
    v = p.substr(i+1,p.size() - (i+1));
    
    if(isValid(u)){
        return u + go(v);
    }else{
        string t;
        t.append("(");
        t.append(go(v));
        t.append(")");
        u.erase(u.begin());
        u.erase(u.end()-1);
        reverse(u);
        t= t+u;
        return t;
    }
}



string solution(string p) {
    string answer = "";
    if (isValid(p)){
        return p;
    }else{
        answer = go(p);
        return answer;
    }

}