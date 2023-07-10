#include <iostream>

using namespace std;

const int MAX = 50;
int N, S;
int arr[MAX];

void swap(int i, int j) {
	if (arr[i] < arr[j]) {
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}
void sort_arr(int cnt) {
	for (int i = 0; i < N - 1 && cnt; i++) {
		int max = arr[i];
		int max_idx = i;

		for (int j = i + 1; j <= i + cnt && j < N; j++) {
			if (max < arr[j]) {
				max = arr[j];
				max_idx = j;
			}
		}
		if (i != max_idx) {
			while (max_idx != i) {
				swap(max_idx - 1, max_idx);
				max_idx--;
				cnt--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> S;
	sort_arr(S);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}