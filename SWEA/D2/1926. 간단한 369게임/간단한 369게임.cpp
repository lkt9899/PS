#include <iostream>

using namespace std;

int n;
void run();

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin >> n;
	run();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void run() {
	int tmp;
	for (int i = 1; i <= n; i++) {
		tmp = i;
		int cnt = 0;
		while (tmp != 0) {
			int a = tmp % 10;
			if(a != 0 && a % 3 == 0) {
				cnt++;
			}
			tmp /= 10;
		}
		if (cnt != 0) {
			for(int j = 0; j < cnt; j++) {
				cout << "-";
			}
		}
		else {
			cout << i;
		}
		cout << " ";
	}
}