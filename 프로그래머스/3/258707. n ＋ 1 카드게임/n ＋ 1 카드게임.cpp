#include <set>
#include <vector>

using namespace std;

int N, C, answer;
set<int> hands, pick;

bool check(set<int> &f, set<int> &m) {
    for (auto card : f) {
        int toFind = N + 1 - card;
        if (m.find(toFind) != m.end()) {
            f.erase(card);
            m.erase(toFind);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    // init
    answer = 1;
    N = cards.size();
    C = coin;
    
    // draw
    int idx = N / 3;
    for (int i = 0; i < idx; i++) {
        hands.insert(cards[i]);
    }

    while (idx < N) {
        // pick
        pick.insert(cards[idx]);
        pick.insert(cards[idx + 1]);
        idx += 2;

        // check
        if (hands.size() >= 2 && check(hands, hands)) {
            answer++;
        } else if (C >= 1 && hands.size() >= 1 && pick.size() >= 1 && check(hands, pick)) {
            answer++;
            C--;
        } else if (C >= 2 && pick.size() >= 2 && check(pick, pick)) {
            answer++;
            C -= 2;
        } else
            break;
    }

    return answer;
}