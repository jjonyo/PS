/*
	21.01.08
	BOJ : 19238 스타트 택시 (https://www.acmicpc.net/problem/19238)
	구현,시뮬레이션,BFS
*/
#include <bits/stdc++.h>
using namespace std;


typedef struct taxi {
	int x;
	int y;
}taxi;

typedef struct person {
	int dist;
	int x;
	int y;
}person;

int board[22][22]; //지도 (승객)

int fuel; //연료
int dist[22][22]; //방문확인
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

taxi T;
int N, M;
vector <person> info;
vector <pair<int, int>> dest;

bool cmp(person a,person b) {
	if (a.dist == b.dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else
			return a.x < b.x;
	}
	else
		return a.dist < b.dist;
}

void BFS() {
	info.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = -1;
		}
	}

	queue <pair<int, int>> Q;
	Q.push({ T.x,T.y });
	dist[T.x][T.y] = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		if (board[cur.first][cur.second] > 0) { //승객 찾음
			int d = dist[cur.first][cur.second];
			info.push_back({d,cur.first,cur.second});
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx <1 || ny<1 || nx>N || ny>N) continue;
			if (board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			if (dist[nx][ny] > fuel) continue;
			Q.push({ nx,ny });
		}
	}
}

int Find(int num) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = -1;
		}
	}

	queue <pair<int, int>> Q;
	Q.push({ T.x,T.y });
	dist[T.x][T.y] = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		if (dest[num].first ==cur.first && dest[num].second == cur.second) { //목적지 찾음
			T.x = cur.first;
			T.y = cur.second;
			return dist[cur.first][cur.second];
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx <1 || ny<1 || nx>N || ny>N) continue;
			if (board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			if (dist[nx][ny] > fuel) continue;
			Q.push({ nx,ny });
		}
	}

	return -1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M >> fuel;
	dest.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) //벽 -1로
				board[i][j] = -1; 
		}
	}

	cin >> T.x >> T.y;

	
	for (int i = 1; i <= M; i++) {
		int fromX, fromY, toX, toY;
		cin >> fromX >> fromY >> toX >> toY;

		board[fromX][fromY] = i;
		dest.push_back({ toX,toY });
	}
	int cnt = 0;

	while (true) {
		if (cnt == M) {
			break;
		}
		//가장 가까운 승객 찾기
		BFS();
		sort(info.begin(), info.end(), cmp);
		if (info.size() == 0) { //태울 수 있는 승객 없음
			cout << -1;
			return 0;
		}

		int nx = info[0].x;
		int ny = info[0].y;
		int d = info[0].dist;
		int num = board[nx][ny];

		//승객 지우기
		board[nx][ny] = 0;

		if (d > fuel) { //이동 불가
			cout << -1;
			return 0;
		}

		//승객위치 까지 이동하기
		T.x = nx;
		T.y = ny;
		fuel = fuel - d;

		//목적지까지 거리 찾기
		int destDist = Find(num);

		//이동하기
		if (destDist == -1 || destDist > fuel) {
			cout << -1;
			return 0;
		}
		fuel = fuel - destDist;

		//연료채우기
		fuel = fuel + destDist * 2;
		cnt++;
	}

	cout << fuel;
	return 0;
}