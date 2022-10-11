#include <bits/stdc++.h>
#define MAX_N 5001

using namespace std;

struct Node {
    int data;
    Node* prev, *next;
}node_pool[MAX_N];

int nodeCnt;
Node* head;
int N, K;

static inline Node* get_tail() {
    return head->prev;
}

static inline Node* alloc(int data) {
    node_pool[nodeCnt].data = data;
    node_pool[nodeCnt].next = &node_pool[nodeCnt];
    node_pool[nodeCnt].prev = &node_pool[nodeCnt];

    return &node_pool[nodeCnt++];
}

static inline void append2tail(Node* n) {
    n->prev = get_tail();
    n->next = head->next;
    n->next->prev = n;
    n->prev->next = n;
    head->prev = n;
}

static inline void remove(Node* n) {
    n->next->prev = n->prev;
    n->prev->next = n->next;
}

void init() {
    nodeCnt = 0;
    head = alloc(0);
    cin >> N >> K;
}

void run() {
    Node* node;
    init();

    for(int i = 1; i <= N; i++) {
        node = alloc(i);
        append2tail(node);
    }

    node = head;
    cout << "<";
    for(int i = 0; i < N; i++) {
        int cnt = K;
        while(cnt != 0) {
            node = node->next;
            cnt--;
        }
        cout << node->data;
        if(i < N-1) cout << ", ";
        remove(node);
        node = node->prev;
    }
    cout << ">";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();

    return 0;
}