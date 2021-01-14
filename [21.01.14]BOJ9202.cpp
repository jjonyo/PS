/*
	21.01.14
	BOJ : 9202 Boggle (https://www.acmicpc.net/problem/9202)
	자료구조/트라이
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* child[26];
	bool isEnd = false;
	bool isHit = false;
	int length = 0;

	Node() { memset(child, NULL, sizeof(child)); }
	void clearHit() {
		isHit = false;
		for (int i = 0; i < 26; i++) {
			if (child[i] != NULL) {
				child[i]->clearHit();
			}
		}
	}
};

Node root;
int score[10] = { 0,0,0,1,1,2,3,5,11,0};
char board[4][4];
bool vis[4][4];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int totalScore = 0;
string maxWord;
string currentWord;
int maxWordLength = 0;
int totalCount = 0;

void insert(string word) {
	Node* current = &root;

	int len = word.size();
	for (int i = 0; i < len; i++) {
		int wordIndex = word[i] - 'A';
		if (current->child[wordIndex] == NULL) {
			current->child[wordIndex] = new Node;
		}
		current = current->child[wordIndex];
	}
	current->isEnd = true;
	current->length = len;
}

void dfs(int r, int c,Node* cur) {
	if (cur == NULL) return;
	vis[r][c] = 1;

	if (cur->isEnd) { //단어가 완성되는 시점에서
		if (!cur->isHit) { //단어가 아직 Hit되지 않았을 경우
			totalCount++;
			totalScore += score[cur->length];
			if (cur->length >= maxWordLength) {
				if (cur->length == maxWordLength) { //길이가 같다면 사전순으로 앞서는 단어 선택
					if (currentWord < maxWord) {
						maxWord = currentWord;
					}
				}
				else {
					maxWordLength = cur->length;
					maxWord = currentWord;
				}
			}

			cur->isHit = true;
		}
	}

	for (int dir = 0; dir < 8; dir++) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];
		int nxt = board[nx][ny] -'A';
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || vis[nx][ny]) continue;
		currentWord.append(string(1, board[nx][ny]));
		dfs(nx, ny, cur->child[nxt]);
		currentWord.erase(currentWord.size() - 1);
	}

	vis[r][c] = 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, T;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		insert(str);
	}
	
	cin >> T;

	while(T--) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}

		maxWord.clear();
		root.clearHit();
		maxWordLength = 0;
		totalScore = 0;
		totalCount = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int nxt = board[i][j] - 'A';
				currentWord.append(string(1,board[i][j]));
				dfs(i, j,root.child[nxt]);
				if (currentWord.size() > 0) currentWord.clear();
			}
		}

		cout << totalScore << " " << maxWord << " " << totalCount<<'\n';
	}
	
	return 0;
}