#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 2000

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

Node node[MAX];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;

    return &node[nodeCnt++];
}

void Init() {
    nodeCnt = 0;
    head = new Node;
}

void insert(int x, int n) {
    Node* cur = head;
    Node* node = getNode(n);
    Node* next;

    for(int i = 0; i < x; i++) {
        cur = cur->next;
    }
    if(cur->next) {
        next = cur->next;
        node->next = next;
        cur->next = node;
    }
    else {
        cur->next = node;
    }
    
}

void remove(int x) {
    Node* cur = head;
    Node* toRemove;
    if(x == 0) head->next = head->next->next;

    else {
        for(int i = 0; i < x; i++) cur = cur->next;
        toRemove = cur->next;

        if(toRemove->next)  cur->next = toRemove->next;
        else    cur->next = nullptr;
    }
    
}

void change(int x, int n) {
    Node* cur = head->next;
    for(int i = 0; i < x; i++) cur = cur->next;
    cur->data = n;
}

void getCmd(char cmd) {
    int x, n;
    switch(cmd) {
        case 'I' :
            cin >> x >> n;
            insert(x, n);
            break;
        case 'D' :
            cin >> x;
            remove(x);
            break;
        case 'C' :
            cin >> x >> n;
            change(x, n);
            break;
    }
}

void setList(int N) {
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        insert(i, num);
    }
}

int getData(int L) {
    Node* cur = head->next;
    for(int i = 0; i < L; i++) {
        if(cur->next)   cur = cur->next;
        else return -1;
    }

    return cur->data;
}

int main(int argc, char** argv)
{
    fio;
    int test_case, T, N, M, L;
    
    // remove this when submit
    freopen("13501.txt", "r", stdin);

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> L;
        Init();
        setList(N);

        for(int j = 0; j < M; j++) {
            char cmd; cin >> cmd;
            getCmd(cmd);
        }
        cout << "#" << test_case << " " << getData(L) << "\n";
    }
    return 0;
}