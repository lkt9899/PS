#include <iostream>
#include <string>

using namespace std;

string s;
int ans;

void input() {
	cin >> s;
}

void run() {
	int len = s.length();
	int max_len;

	if (len % 2 == 0) max_len = len / 2;
	else max_len = len / 2 + 1;

	string s1, s2;

	s1 = s.substr(0, max_len);
	s2 = s.substr(len - max_len);

	if (stoi(s1) < stoi(s2)) {
		ans = stoi(s1) + stoi(s.substr(max_len));
	}
	else {
		ans = stoi(s2) + stoi(s.substr(0, len - max_len));
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		input();
		run();

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}
