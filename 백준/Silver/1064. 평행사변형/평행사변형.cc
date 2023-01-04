#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
};

double getInc(Point p1, Point p2) {
    double y = abs(p1.y - p2.y);
    double x = abs(p1.x - p2.x);
    if(x == 0) return INT_MAX;
    else return y / x;
}

double getDist(Point p1, Point p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x*x + y*y);
}

int main() {
    Point pts[3];
    double dist[3];
    for(int i = 0; i < 3; i++) {
        scanf("%lf %lf", &pts[i].x, &pts[i].y);
    }

    if(getInc(pts[0], pts[1]) == getInc(pts[0], pts[2])) cout << "-1.0";
    else {
        for(int i = 0; i < 3; i++) {
            dist[i] = getDist(pts[i], pts[(i+1) % 3]) * 2.0;
        }
        sort(dist, dist+3);
        printf("%.16f", (dist[2] - dist[0]));
    }

    return 0;
}