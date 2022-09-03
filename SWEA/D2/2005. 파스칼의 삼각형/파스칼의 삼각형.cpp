#include<iostream>
#include <algorithm>

using namespace std;
void print(int n) {
	cout << n << ' ';
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << endl;
		int N;
        int temp = 1;
        int pre[10];
        int cur[10];
        
        cin >> N;
        
        for(int i = 0; i < N; i++) {
        	for(int j = 0; j <= i; j++) {
            	if((j == 0) || (j == i)) {
                	print(1);
                    cur[j] = 1;
                }
                else {
                	print(pre[j-1] + pre[j]);
                    cur[j] = pre[j-1] + pre[j];
                }
            }
            cout << endl;
            copy(cur, cur+10, pre);
        }
	}
	return 0;
}