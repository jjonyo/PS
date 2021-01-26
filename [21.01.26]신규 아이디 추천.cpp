#include <string>
#include <vector>
#include <iostream>

using namespace std;
void step1(string &id){
    int len = id.size();
    
    for (int i=0;i<len;i++){
        if (id[i] >='A' && id[i] <='Z'){ 
            id[i] = id[i] + 32;
        }
    }
}

string step2(string &id){
    string answer;
    int len = id.size();
    for (int i=0;i<len;i++){
        if (id[i] == '-' || (id[i] >='a' && id[i] <='z') || isdigit(id[i]) || id[i] =='_' || id[i] =='.'){
            answer.append(string(1,id[i]));
        }
    }
    
    return answer;
}

string step3(string &id){
    string answer;
    int len = id.size();
  
    for (int i=0;i<len-1;i++){
        if (id[i] != '.'){
            answer.append(string(1,id[i]));
        }else if(id[i] == '.' && id[i+1] != '.'){
            answer.append(string(1,'.'));
        }
    }
    answer.append(string(1,id[len-1]));
    
    return answer;
}

void step4(string &id){
    if (id[0] == '.'){
        id.erase(id.begin());
    }
    
    if(id.back() == '.'){
        id.erase(id.size()-1);
    }
}

void step5(string& id){
    if (id.size() == 0){
        id.append(string(1,'a'));
    }
}

string step6(string &id){
    string answer;
    if (id.size() >= 16){
        for (int i=0;i<15;i++){
            answer.append(string(1,id[i]));
        }
        
        if (answer.back() == '.'){
        answer.erase(answer.size()-1);
    }
    }else{
        answer = id;
    }
    
    return answer;
}

void step7(string &id){
    if (id.size() <= 2){
        while(id.size ()<3){
            id.append(string(1,id.back()));
        }
    }
}

string solution(string new_id) {
    string answer = new_id;
    
    step1(answer);
    answer = step2(answer);
    answer = step3(answer);
    step4(answer);
    step5(answer);
    answer = step6(answer);
    step7(answer);
    
    return answer;
}