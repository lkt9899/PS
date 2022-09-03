#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, a;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        vector<int> p;
        
        for(int i = 0; i < N; i++) {
        	cin >> a;
            p.push_back(a);
        }

        long long answer = 0;
        int max;
        max = *--p.end();
        for(int i = p.size() - 2; i >= 0; i--) {
            if(p[i] >= max)
                max = p[i];
            else
                answer += max - p[i];
        }
        cout << "#" << test_case << " " <<  answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}