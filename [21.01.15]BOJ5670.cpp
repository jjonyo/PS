/*
	21.01.15
	BOJ : 5670 휴대폰 자판 (https://www.acmicpc.net/problem/5670)
	자료구조/트라이
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* child[26];
	bool isEnd;
	int childCount;

	Node() { 
		memset(child, NULL, sizeof(child)); 
		isEnd = false;
		childCount = 0;
	}

};

void insert(string word,Node *root) {
	Node* current = root;

	int len = word.size();
	for (int i = 0; i < len; i++) {
		int nxt = word[i] - 'a';
		if (current->child[nxt] == NULL) {
			current->child[nxt] = new Node;
			current->childCount += 1;
		}
		current = current->child[nxt];
	}

	current->isEnd = true;
}

int query(string word,Node *root) {
	Node* current = root->child[word[0] - 'a'];
	int ret = 1;
	int len = word.size();
	for (int i = 1; i < len; i++) {
		int nxt = word[i] - 'a';

		if (current->childCount == 1 && current->isEnd == false) { //갈 수 있는 단어가 1개만 존재
			current = current->child[nxt];
		}
		else {
			current = current->child[nxt];
			ret++;
		}
	}

	return ret;
}

void clear(Node* cur) {
	for (int i = 0; i < 26; i++) {
		if (cur->child[i] != NULL) {
			clear(cur->child[i]);
		}
	}

	delete cur;
}

vector <string> words;


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(0);
	Node root;
	while (true) {
		int N;
		cin >> N;
		if (cin.eof()) break;
	
		Node* root = new Node;
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			words.push_back(temp);
		}
	
		//단어 INSERT
		for (string& v : words) {
			insert(v,root);
		}

		int cnt = 0;
		for (string& v : words) {
			cnt += query(v,root);
		}

		printf("%.2f\n", (float)cnt / N);
		
		words.clear();
		clear(root);
	}

	return 0;
}