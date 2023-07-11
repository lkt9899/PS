#include <iostream>
#include <cstring>
#include <queue>
#include <stdio.h>

using namespace std;

struct Customer
{
    int i, j, dist;
};

bool operator < (const Customer &a, const Customer &b) {
    if(a.dist == b.dist) {
        if(a.i == b.i) {
            return a.j < b.j;
        } else {
            return a.i < b.i;
        }
    } else {
        return a.dist < b.dist;
    }
}

const int N_MAX = 21;
const int INF = 1 << 20;
int N, M, F, si, sj, ci, cj, gi, gj, cd, gd, cnt;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int map[N_MAX][N_MAX] = {0, };
int dist[N_MAX][N_MAX];
Customer target[N_MAX][N_MAX];

void init()
{
    cd = gd = INF;
    memset(dist, -1, sizeof(dist));
}

void find_person()
{
    queue<Customer> q;
    q.push({si, sj});
    dist[si][sj] = 0;

    if(map[si][sj] == -1) {
        ci = si, cj = sj;
        cd = dist[ci][cj];
    }

    while(!q.empty()) {
        Customer cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ni = cur.i + di[i], nj = cur.j + dj[i];

            if(ni < 1 || ni > N || nj < 1 || nj > N) continue;

            if(map[ni][nj] != 1 && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[cur.i][cur.j] + 1;

                if(map[ni][nj] == -1) {
                    Customer next = {ni, nj, dist[ni][nj]};
                    Customer tar = {ci, cj, cd};

                    if(next < tar) {
                        ci = ni, cj = nj;
                        cd = dist[ni][nj];
                    }
                } 
                q.push({ni, nj});
            }
        }
    }
}

void goTarget() {
    queue<Customer> q;
    q.push({ci, cj});
    dist[ci][cj] = 0;

    while(!q.empty()) {
        Customer cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ni = cur.i + di[i], nj = cur.j + dj[i];

            if(ni < 1 || ni > N || nj < 1 || nj > N) continue;

            if(map[ni][nj] != 1 && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[cur.i][cur.j] + 1;

                if(ni == gi && nj == gj) {
                    gd = dist[ni][nj];
                }
                q.push({ni, nj});
            }
        }
    }
    
}

void run()
{
    cnt = M;
    while(cnt) {
        init();
        find_person();

        if(F < cd) break;

        F -= cd;
        map[ci][cj] = 0;

        gi = target[ci][cj].i, gj = target[ci][cj].j;
        init();
        goTarget();

        if(F < gd) break;

        F += gd;
        cnt--;

        si = gi, sj = gj;
    }

    if(cnt > 0) F = -1;

    cout << F;
}

void input()
{
    cin >> N >> M >> F;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    cin >> si >> sj;

    for (int i = 0; i < M; i++)
    {
        cin >> ci >> cj >> gi >> gj;
        map[ci][cj] = -1;
        target[ci][cj] = {gi, gj};
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    run();

    return 0;
}