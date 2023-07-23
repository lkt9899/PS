#include <iostream>
#include <algorithm>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct Square
{
    int x1, y1, x2, y2;
};

char ans;

void check(Square p, Square q)
{
    int l, r, t, b, xd, yd;
    l = max(p.x1, q.x1);
    r = min(p.x2, q.x2);
    b = max(p.y1, q.y1);
    t = min(p.y2, q.y2);
    xd = r - l;
    yd = t - b;

    if (xd > 0 && yd > 0)
        ans = 'a';
    else if (xd < 0 || yd < 0)
        ans = 'd';
    else if (xd == 0 && yd == 0)
        ans = 'c';
    else
        ans = 'b';
}

void run()
{
    for (int i = 0; i < 4; i++)
    {
        Square p, q;
        cin >> p.x1 >> p.y1 >> p.x2 >> p.y2 >> q.x1 >> q.y1 >> q.x2 >> q.y2;
        check(p, q);
        cout << ans << "\n";
    }
}

int main()
{
    fio;
    run();
    return 0;
}