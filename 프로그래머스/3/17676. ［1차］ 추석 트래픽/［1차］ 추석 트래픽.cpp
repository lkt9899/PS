#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct Info {
    int start;
    int end;
};

vector<Info> infos;

void getInfo(vector<string> lines) {
    for(string s : lines) {
        int hour = stoi(s.substr(11, 2)) * 3600 * 1000;
        int min = stoi(s.substr(14, 2)) * 60 * 1000;
        int sec = stod(s.substr(17, 6)) * 1000;
        int diff = stod(s.substr(24, 5)) * 1000;
        
        int end = hour + min + sec;
        int start = end - diff + 1;
        
        infos.push_back({start, end});
    }
}

int sol() {
    int ans = 0;
    for(int i = 0; i < infos.size(); i++) {
        int cnt = 1;
        int right = infos[i].end + 999;
        for(int j = i + 1; j < infos.size(); j++) {
            if(right >= infos[j].start)
                cnt++;
        }
        ans = ans > cnt ? ans : cnt;
    }
    
    return ans;
}

int solution(vector<string> lines) {
    getInfo(lines);
    for(Info info : infos) {
        cout << "start : " << info.start << " end : " << info.end << "\n";
    }
    return sol();
}