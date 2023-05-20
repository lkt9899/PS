#include <iostream>
#include <cstring>

using namespace std;

int ans, dump;
int arr[101];

void init() {
	memset(arr, 0, sizeof(arr));
	dump = 0;
}

void input() {
	cin >> dump;
	int h;
	for (int i = 0; i < 100; i++) {
		cin >> h;
		arr[h]++;
	}
}

void swap(int left, int right) {
	arr[left]--;
	arr[left + 1]++;
	arr[right]--;
	arr[right - 1]++;
	dump--;
}

void run() {
	int left = 0, right = 100;
	
	while (dump != 0) {
		if (right - left <= 1) break;
		if(arr[left] != 0 && arr[right] != 0) swap(left, right);
		if (arr[left] == 0) left++;
		if (arr[right] == 0) right--;
	}
	ans = right - left;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		run();

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}