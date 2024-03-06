#include <string>
#include <stack>

using namespace std;

stack<int> st;

void addScore(int score, char bonus) {
    switch(bonus) {
        case 'S':
            st.push(score);
            break;
        case 'D':
            st.push(score * score);
            break;
        case 'T':
            st.push(score * score * score);
            break;
        default:
            break;
    }
}

void runCmd(char c) {
    int score1, score2;
    switch(c) {
        case '*':
            score1 = st.top();
            st.pop();
            if(st.empty()) {
                st.push(score1 * 2);
                break;
            }
            score2 = st.top();
            st.pop();
            
            st.push(score2 * 2);
            st.push(score1 * 2);
            break;
        case '#':
            score1 = st.top();
            st.pop();
            st.push(-score1);
            break;
        default:
            break;
    }
}

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

int solution(string dartResult) {
    int answer = 0;
    for(int i = 0; i < dartResult.size(); i++) {
        char c = dartResult[i];
        if(isNumber(c)) {
            int score;
            if(isNumber(dartResult[i + 1])) {
                score = 10;
                i++;
            } else score = c - '0';
            
            char bonus = dartResult[++i];
            addScore(score, bonus);
        } else {
            runCmd(c);
        }
    }

    while(!st.empty()) {
        answer += st.top();
        st.pop();
    }
    
    return answer;
}