#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int max_ch, length, _max;
string s;

void init() {
	max_ch = 0;
	_max = 0;
}

void input() {
	cin >> s >> max_ch;
	length = s.length();
}

void swap(int i1, int i2) {
	char tmp = s[i1];
	s[i1] = s[i2];
	s[i2] = tmp;
}

void dfs(int st, int cnt) {
	if (cnt == max_ch) {
		_max = max(_max, stoi(s));
		return;
	}
	for(int i = st; i < length; i++)
		for (int j = i + 1; j < length; j++) {
			swap(i, j);
			dfs(i, cnt + 1);
			swap(i, j);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		if (max_ch > length) max_ch = length;
		dfs(0, 0);

		cout << "#" << test_case << " " << _max << "\n";
	}
	return 0;
}