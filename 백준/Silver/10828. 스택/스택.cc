#include <bits/stdc++.h>
#define MAX_N 10001

using namespace std;

int arr[MAX_N];
int it = -1;
int N;

void push(int x) {
    arr[++it] = x;
}

void pop() {
    if(it == -1) cout << it << "\n";
    else    cout << arr[it--] << "\n";
}

void top() {
    if(it == -1) cout << it << "\n";
    else    cout << arr[it] << "\n";
}

void empty() {
    cout << (it == -1) << "\n";
}

void size() {
    cout << it+1 << "\n";
}

void run() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        
        if(cmd == "push") {
            int x; cin >> x;
            push(x);
        }
        else if(cmd == "pop") {
            pop();
        }
        else if(cmd == "size") {
            size();
        }
        else if(cmd == "top") {
            top();
        }
        else if(cmd == "empty") {
            empty();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();

    return 0;
}