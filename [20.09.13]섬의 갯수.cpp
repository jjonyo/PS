/*
20.09.14 코딩부트 캠프 연습문제
LEVEL 2 섬의 갯수 
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

/*
example input
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/

int board[MAX][MAX]; //육지와 바다를 입력받을 배열
bool visit[MAX][MAX]; //방문을 확인할 배열
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 };
int N, M;

int solution()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 || visit[i][j] == 1 ) continue; //이미 방문했거나 바다라면 continue
           
            //BFS 수행
            queue <pair<int,int>> Q;
            visit[i][j] = 1; //현재 노드 방문 처리
            Q.push({ i,j }); //큐에 PUSH

            while (!Q.empty())
            {
                int cur_x = Q.front().first; //현재 x좌표
                int cur_y = Q.front().second; //현재 y좌표
                Q.pop();
                for (int dir = 0; dir < 4; dir++) //현재노드 기준 네가지 방향에 대해 탐색 수행
                {
                    int nx = cur_x + dx[dir]; //다음 탐색할 좌표들
                    int ny = cur_y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; //다음 좌표가 board의 크기를 넘을시 continue
                    if (board[nx][ny] == 0 || visit[nx][ny] == 1) continue; //다음 방문할 곳이 이미 방문했거나 바다라면 continue
                    visit[nx][ny] = 1; //방문 처리
                    Q.push({ nx,ny });
                }
            }
            ans++; //인접한 영역에 대해 BFS수행 후에 ans값 증가
        }
    }

    return ans;
}

int main(void) {

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    
    cout << solution();
}
