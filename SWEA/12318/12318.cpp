#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

///////////////////////////////////////////////////////
struct Point
{
	int x, y;

	Point operator+(Point b)
	{
		Point tmp;
		tmp.x = x + b.x;
		tmp.y = y + b.y;

		return tmp;
	}
} q[100];

int m[10][10];
int m_size;
int d[10][10];
int visit[10][10];
Point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int head = 0;
int tail = 0;

void push(Point p)
{
	q[tail++] = p;
}

Point pop()
{
	return q[head++];
}

bool empty()
{
	return (head == tail);
}

void bfs_init(int map_size, int map[10][10])
{
	m_size = map_size;
	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			m[i][j] = map[i][j];
			
		}
	}
}

int bfs(int x1, int y1, int x2, int y2)
{
	head = 0;
	tail = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			d[i][j] = 0;
			visit[i][j] = false;
		}
	}

	Point start = {x1 - 1, y1 - 1};
	Point end = {x2 - 1, y2 - 1};

	push(start);
	while (!empty())
	{
		Point p = pop();
		visit[p.y][p.x] = true;

		Point next;
		for (int i = 0; i < 4; i++)
		{
			next = p + dir[i];
			if (next.x < 0 || next.x > 9 || next.y < 0 || next.y > 9 || m[next.y][next.x] == 1)
				continue;

			if (visit[next.y][next.x] != true)
			{
				d[next.y][next.x] = d[p.y][p.x] + 1;
				if (next.y == end.y && next.x == end.x)
					return d[end.y][end.x];
				push(next);
			}
		}
	}

	return -1;
}
///////////////////////////////////////////////////////

static int test_bfs()
{
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist)
			score = 0;
	}
	return score;
}

int main()
{
	setbuf(stdout, NULL);

	freopen("12318.txt", "r", stdin);
	printf("#total score : %d\n", test_bfs());

	return 0;
}