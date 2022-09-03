#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10001

using namespace std;

struct Node
{
    int children[2] = {0, 0};
} node[MAX];

int V, E, i, j, parent, answer;
int table[MAX];
int par[MAX];
int chd[MAX];

void Init()
{
    memset(table, -1, sizeof(table));
    memset(par, 0, sizeof(par));
    memset(chd, 0, sizeof(chd));
    answer = 0;
}

void makeTable(int E)
{
    int p, c;
    for (int i = 0; i < E; i++)
    {
        cin >> p >> c;
        table[c] = p;
        if (chd[p] == 0)
        {
            node[p].children[0] = -1;
            node[p].children[1] = -1;
            node[p].children[0] = c;
            chd[p]++;
        }
        else
        {
            node[p].children[1] = c;
            chd[p]++;
        }
    }
}

void find_parent(int i, int j)
{
    queue<int> q;
    q.push(i);
    q.push(j);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        if (c == 1)
            continue;
        if (table[c] != -1)
            q.push(table[c]);
        par[table[c]]++;
        if (par[table[c]] == 2) {
            parent = table[c];
            break;
        }
    }
}

void calcCnt(int idx)
{
    if(idx == 1) {
        answer = V;
    }
    else {
        queue<int> q;
        q.push(idx);
        while (!q.empty())
        {
            idx = q.front();
            q.pop();
            answer++;

            if (chd[idx] != 0)
            {
                for (int i = 0; i < chd[idx]; i++)
                {
                    int n = node[idx].children[i];
                    if (n != -1)
                        q.push(n);
                }
            }
        }
    }
    
}

int main(int argc, char **argv)
{
    fio;
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> V >> E >> i >> j;
        Init();
        makeTable(E);
        find_parent(i, j);
        calcCnt(parent);
        cout << "#" << test_case << " " << parent << " " << answer << "\n";
    }
    return 0;
}