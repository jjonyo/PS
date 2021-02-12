#include <string>
#include <map>
#include <cctype>
#include <iostream>
using namespace std;

map <string,int> m1;
map <string,int> m2;

string Upper(string a){
    string ret;
    for (int i=0;i<a.size();i++){
        ret += toupper(a[i]);
    }
    
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    str1 = Upper(str1);
    str2 = Upper(str2);
    
    int f=0;
    int s=0;
    double res=0;
    
    for (int i=0;i<str1.size()-1;i++){
        if (!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        string temp;
        temp += str1[i];
        temp += str1[i+1];
        m1[temp]++;
    }
    
        for (int i=0;i<str2.size()-1;i++){
        if (!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        string temp;
        temp += str2[i];
        temp += str2[i+1];
        m2[temp]++;
    }
    
    for (auto cur : m1){
        string temp = cur.first;
        if (m2.find(temp) != m2.end()){
           f += min(m1[temp],m2[temp]);
           s += max(m1[temp],m2[temp]);
            
           m2[temp] = 0;
        }else
            s += cur.second;
    }
    
    for (auto cur : m2){
        s += cur.second;
    }
    
    if (f == 0 && s == 0) res=1;
    else res = (double)f/s;
    
    answer = res * 65536;
    
    
    return answer;
}