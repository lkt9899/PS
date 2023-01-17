#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

#define MAX_SIZE 51
#define MAX_N 1001

struct Node {
    int idx;
    Node *next = nullptr;
}node[MAX_SIZE];

int N;
int P[MAX_SIZE];
int visited[MAX_N];
vector<int> av;
int nodeCnt = 0;
Node* head[MAX_N];

Node* newNode(int idx) {
    node[nodeCnt].idx = idx;

    return &node[nodeCnt++];
}

void linkNode(Node* nPtr, int idx) {
    Node* cur = head[idx];

    while(cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = nPtr;
}

void init() {
    for(int i = 0; i < MAX_N; i++) {
        head[i] = new Node;
    }

    memset(visited, 0, sizeof(visited));
}

void run() {
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;

        if(visited[a]== 0) {
            visited[a] = 1;
            av.push_back(a);
        }

        Node* cur = newNode(i);
        linkNode(cur, a);
    }
}

void fillP() {
    sort(av.begin(), av.end());

    int index = 0;
    for(size_t i = 0; i < av.size(); i++) {
        Node* cur = head[av[i]];
        while(cur->next != nullptr) {
            cur = cur->next;
            P[cur->idx] = index++;
        }
    }
}

void print() {
    for(int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
}

int main()
{
    fio;

    cin >> N;

    init();
    run();
    fillP();
    print();

    return 0;
}