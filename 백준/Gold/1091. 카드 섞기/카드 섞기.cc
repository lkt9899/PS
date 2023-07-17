#include <iostream>
#include <vector>

using namespace std;

const int MAX = 48;
int N, ans = 0;
int P[MAX], S[MAX], visit[MAX] = { 0, };
vector<int> v;

int lcm(int n1, int n2) {
	if (n1 * n2 == 0) {
		return n1 == 0 ? n2 : n1;
	}

	int a = n1, b = n2, c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return (n1 * n2) / a;
}

int getLen(int n) {
	int init = n;
	n = S[n];
	visit[n] = 1;

	int cnt = 1;
	while (n != init) {
		n = S[n];
		visit[n] = 1;
		cnt++;
	}

	return cnt;
}

int getMax() {
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			int cnt = getLen(i);
			v.push_back(cnt);
		}
	}

	int max = v[0];
	for (int i = 1; i < v.size(); i++) {
		max = lcm(max, v[i]);
	}

	return max;
}

bool check() {
	for (int i = 0; i < N; i++) {
		if (P[i] != i % 3)
			return false;
	}

	return true;
}

void shuffle() {
	int tmp[MAX];

	for (int i = 0; i < N; i++) {
		tmp[S[i]] = P[i];
	}

	copy(tmp, tmp + MAX, P);	
	ans++;
}

int main() {
	int maxCnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	
	maxCnt = getMax();
	while (!check()) {
		if (maxCnt == 0) {
			ans = -1;
			break;
		}
		shuffle();
		maxCnt--;
	}
	cout << ans;
}