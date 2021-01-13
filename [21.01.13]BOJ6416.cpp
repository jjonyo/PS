/*
	21.01.13
	BOJ 6416 : 트리인가? (https://www.acmicpc.net/problem/6416)
	자료구조/트리
*/
#include <bits/stdc++.h>
using namespace std;

map <long, pair<long, long>> tree;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tc = 0;
	while (true) {
		tree.clear();
		bool isTree = true;
		int cnt = 0;
		while (true)
		{
			long parent, child;
			cin >> parent >> child;
			if (parent == -1 && child == -1) return 0;
			if (parent == 0 && child == 0) break;

			tree[parent].first += 1;
			tree[child].second += 1;
			if (tree[child].second > 1) { //이미 들어오는 간선이 존재함.
				isTree = false;
			}

			cnt++;
		}
		
		if (isTree) {
			if (tree.size() == 0 || tree.size() - 1 == cnt) {
				cout << "Case " << ++tc << " is a tree.\n";
			}
			else
				cout << "Case " << ++tc << " is not a tree.\n";
		}
		else {
			cout << "Case " << ++tc << " is not a tree.\n";
		}
	}
	return 0; 
}