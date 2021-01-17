/*
	21.01.16
	BOJ : 14725 개미굴 (https://www.acmicpc.net/problem/14725)
	자료구조/트라이
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	map <string, int> index;
	Node* child[20];
	int count;
	int depth;

	Node() {
		memset(child, NULL, sizeof(NULL));
		count = 0;
		depth = 0;
	}
};

Node root;

void insert(vector<string> words) {
	Node* current = &root;
	int depth = 0;
	for (string& word : words) {
		if (current->index.find(word) == current->index.end()) { //존재하지 않음.
			current->index[word] = current->count;
			current->child[current->count] = new Node;
			current->count += 1;
		}
		current->depth = depth++;
		int idx = current->index[word];
		current = current->child[idx];
	}
}

void print(Node* cur) {
	string bar;
	for (int i = 0; i < cur->depth; i++) {
		bar.append("--");
	}
	for (auto iter = cur->index.begin(); iter != cur->index.end(); iter++) {
		string ans = bar + iter->first;
		cout << ans<<'\n';
		int nxt = iter->second;
		print(cur->child[nxt]);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int N;
	cin >> N;

	while (N--) {
		int K;
		cin >> K;
		vector<string> words;
		string temp;
		for (int i = 0; i < K; i++) {
			cin >> temp;
			words.push_back(temp);
		}

		insert(words);
	}

	//출력
	print(&root);
	return 0;
}