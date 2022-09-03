#define fio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#include <bits/stdc++.h>

#define MAX_N 301

using namespace std;

typedef struct
{
    int i, j;
} Axis;

int res, T, N;
string s;
char game[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int di[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
Axis q[90000];
int head;
int tail;

void push(Axis data)
{
    q[tail++] = data;
}

bool empty()
{
    if (head == tail)
    {
        head = 0;
        tail = 0;
        return true;
    }

    return false;
}

Axis pop()
{
    return q[head++];
}

void init()
{
    head = 0;
    tail = 0;
    res = 0;
    cin >> N;
    memset(visit, 0, sizeof(visit));
}

void make_map()
{
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            game[i][j] = s[j];
        }
    }
}

bool check(Axis a)
{
    int ii = a.i;
    int jj = a.j;

    for (int i = 0; i < 8; i++)
    {
        if (game[ii + di[i]][jj + dj[i]] == '*')
            return false;
    }

    return true;
}

void lastcheck() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j] && game[i][j] == '.') res++;
        }
    }
}

void play()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j] && game[i][j] == '.' && check({i, j}))
            {
                visit[i][j] = 1;
                res++;
                Axis a = {i, j};
                push(a);
                while (!empty())
                {
                    a = pop();
                    Axis tmp;
                    for (int k = 0; k < 8; k++)
                    {
                        tmp = {a.i + di[k], a.j + dj[k]};
                        if (tmp.i < 0 || tmp.i >= N || tmp.j < 0 || tmp.j >= N || visit[tmp.i][tmp.j] != 0 || game[tmp.i][tmp.j] == '*')
                            continue;
                        visit[tmp.i][tmp.j] = 1;
                        if (check(tmp))
                            push(tmp);
                    }
                }
            }
        }
    }
    lastcheck();
}

void print(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << game[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char **argv)
{
    fio;
    int test_case;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        init();
        make_map();
        play();
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}