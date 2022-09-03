// 암호문 3
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX_NODE 1000000

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	return &node[nodeCnt++];
}

void Init() {
    nodeCnt = 0;
    head = new Node;
    tail = new Node;
}

void addNodes2Tail(int y)  {
    int data;
	for(int i = 0; i < y; i++) {
        if(tail->next) {
            Node* cur = tail->next;
            cin >> data;
            Node* node = getNode(data);
            node->prev = cur;
            cur->next = node;
            tail->next = node;
        }
        else {
            cin >> data;
            Node* node = getNode(data);
            head->next = node;
            tail->next = node;
        }
    }
}

void insertNodes(int x, int y) {
    Node* cur = head;
    Node* next;
    int data;
    
    for(int i = 0; i < x; ++i) {
        cur = cur->next;
    }
    if(x == 0) {
        next = cur->next;
        cin >> data;
        Node* node = getNode(data);
        next->prev = node;
        node->next = next;
        cur = node;
        head->next = node;
        y--;
    }
    
    if(cur->next) {
        next = cur->next;
        for(int i = 0; i < y; i++) {
            cin >> data;
            Node* node = getNode(data);
            node->prev = cur;
            cur->next = node;
            cur = node;
        }
        next->prev = cur;
        cur->next = next;
    }
    else {
        for(int i = 0; i < x; i++) {
            cin >> data;
            Node* node = getNode(data);
            node->prev = cur;
            cur->next = node;
            cur = node;
        }
        tail->next = cur;
    }
    
}

void removeNodes(int x, int y) {
	Node* cur = head;
    Node* next;

    for(int i = 0; i < x; i++) {
        cur = cur->next;
    }
    next = cur;
    for(int i = 0; i < y; i++) {
        next = next->next;
    }
    if(next->next) {
        next = next->next;
        next->prev = cur;
        cur->next = next;
    }
    else {
        cur->next = nullptr;
        tail->next = cur;
    }
}

void getCmd(int M) {
	char cmd;
    int x, y, data;
    
    for(int i = 0; i < M; i++) {
        cin >> cmd;
        switch(cmd) {
            case 'I' :
                cin >> x >> y;
                insertNodes(x, y);
                break;
            case 'D' :
                cin >> x >> y;
                removeNodes(x, y);
                break;
            case 'A' :
                cin >> y;
                addNodes2Tail(y);
                break;
        }
    }
}

void print() {
	Node* cur = head;
    for(int i = 0; i < 10; i++) {
        cur = cur->next;
        cout << cur->data << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
    fio;
    int test_case, N, M;
    int T=10;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        Init();
        cin >> N;
        addNodes2Tail(N);

        cin >> M;
        getCmd(M);
        cout << "#" << test_case << " ";
        print();
    }
    return 0;
}