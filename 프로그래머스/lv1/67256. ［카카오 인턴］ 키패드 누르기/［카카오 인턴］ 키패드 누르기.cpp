#include <string>
#include <vector>

using namespace std;

#define LEFT    0
#define RIGHT   1

struct POS {
    int r;
    int c;
};

POS getaxis(int n) {
    POS res;
    
    if(n == 0) {
        res.r = 3;
        res.c = 1;
    }
    else {
        res.r = (n - 1) / 3;
        res.c = (n - 1) % 3;
    }
    
    return res;
}

int dist(const POS& a, const POS& b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

int myhand(string hand) {
    if(hand == "right") return RIGHT;
    else                return LEFT;
}

string L(const POS& c, POS& l) {
    l.r = c.r;
    l.c = c.c;
    
    return "L";
}

string R(const POS& c, POS& r) {
    r.r = c.r;
    r.c = c.c;
    
    return "R";
}

string check(const POS& c, const int& mode, POS& l, POS& r) {
    int ld = dist(c, l);
    int rd = dist(c, r);
    
    if(ld < rd)
        return L(c, l);
    else if(ld > rd)
        return R(c, r);
    else {
        if(mode)
            return R(c, r);
        else
            return L(c, l);
    }
}

// void print(POS p) {
//     cout << "row : " << p.r << ",\tcol : " << p.c << endl;
// }

POS lpos;
POS rpos;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    lpos.r = 3, lpos.c = 0;
    rpos.r = 3, rpos.c = 2;
    
    int mode = myhand(hand);
    
    for(auto n : numbers) {
        POS cur = getaxis(n);
        int col = cur.c;
        
        if(col == 0)
            answer += L(cur, lpos);
        else if(col == 2)
            answer += R(cur, rpos);
        else
            answer += check(cur, mode, lpos, rpos);
        // print(rpos);
        // print(lpos);
    }
    
    return answer;
}