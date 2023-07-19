#include <iostream>
#include <vector>
#include <cstring>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 51;
int N, M, knowCnt, pCnt, ans;
int know[MAX], visit[MAX];
vector<int> person[MAX];

void init() {
	ans = 0;
	memset(visit, 0, sizeof(visit));
}

void getAns() {
	for (int i = 0; i < M; i++) {
		if (visit[i] == 0) ans++;
	}
}

void update(int idx) {
	for (int i = 0; i < person[idx].size(); i++) {
		know[person[idx][i]] = 1;
	}
	visit[idx] = 1;
}

void check() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < person[i].size(); j++) {
			if (visit[i] == 0 && know[person[i][j]] == 1) {
				update(i);
				check();
			}
		}
	}
}

void sol() {
	check();
	getAns();
	cout << ans << "\n";
}

void input() {
	cin >> N >> M;
	cin >> knowCnt;
	for (int i = 0; i < knowCnt; i++) {
		int p;
		cin >> p;
		know[p] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> pCnt;
		for (int j = 0; j < pCnt; j++) {
			int p;
			cin >> p;
			person[i].push_back(p);
		}
	}
}

void run() {
	init();
	input();
	sol();
}

int main()
{
	fio;
	run();
}