#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Axis {
	int i, j;
};

const int N_MAX = 100;
const int M_MAX = 70;
int N, M, ans;
int mt[N_MAX][M_MAX];
int visited[N_MAX][M_MAX];
int di[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dj[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void init() {
	memset(visited, 0, sizeof(visited));
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mt[i][j];
		}
	}
}

bool bfs(Axis c) {
    bool isPeak = 1;
	queue<Axis> q;
	q.push(c);
	visited[c.i][c.j] = 1;

	while (!q.empty()) {
		Axis cur = q.front();
		q.pop();

		int x = cur.i, y = cur.j;

		for (int i = 0; i < 8; i++) {
			int ni = x + di[i], nj = y + dj[i];

			if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if (mt[x][y] < mt[ni][nj]) isPeak = 0;
            if (!visited[ni][nj] && mt[x][y] == mt[ni][nj]) {
                visited[ni][nj] = 1;
                q.push({ni, nj});
            }
		}
	}

    return isPeak;
}

void run() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
                if(bfs({ i, j })) ans++;
            }
		}
	}
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	input();
	run();
}

