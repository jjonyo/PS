#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int board[31][31];
int temp[31][31];

bool isHit(char a,char b,char c,char d){
    if (a == b && b== c && c==d) return true;
    else return false;
}

void pang(int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (temp[i][j] == 1 ){
                board[i][j] = 'X';
            }
        }
    }
}
void down(int m,int n){
    for (int line = 0; line < n; line++){
        for (int row = m-2;row >=0; row--){
            if (temp[row][line] == 1) {
                continue;
            }
            
            char cur = board[row][line];
            
            int nxt = row+1;
            while (true){
                if (temp[nxt][line] == 0 || nxt >= m)break;
                nxt++;
                
            }
            
            if (nxt == row+1) continue;
            temp[nxt-1][line] = 0;
            board[row][line] = 'X';
            temp[row][line]=1;
            board[nxt-1][line] = cur;
        }
    }
}

void print(int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%c ",board[i][j]);
        }
        cout<<'\n';
    }
    
    cout<<'\n';
}

int solution(int m, int n, vector<string> eboard) {
    int answer = 0;
    
    
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            board[i][j] = eboard[i][j];
        }
    }
    
    
    while(true){
        int cnt = 0;
        for (int i=0;i<m-1;i++){
            for (int j=0;j<n-1;j++){
                if (isHit(board[i][j],board[i][j+1],board[i+1][j],board[i+1][j+1])){
                    temp[i][j] ? 0:cnt++;
                    temp[i][j+1] ? 0:cnt++;
                    temp[i+1][j] ? 0:cnt++;
                    temp[i+1][j+1] ? 0:cnt++;
                    
                    temp[i][j] = temp[i][j+1] = temp[i+1][j] = temp[i+1][j+1] = 1;
                }
            }
        }

        if (cnt == 0) break;
        
        answer += cnt;
        pang(m,n); 
        down(m,n);
    }
    
    return answer;
}