#include <bits/stdc++.h>

#define MAX_N 600001

using namespace std;

struct Node
{
    char data;
    Node *next, *prev;
} node_pool[MAX_N];

Node *head;
Node *cursor;
string s;
int nodeCnt = 0;
int N, M;

static inline Node *alloc(char data)
{
    node_pool[nodeCnt].data = data;
    node_pool[nodeCnt].next = &node_pool[nodeCnt];
    node_pool[nodeCnt].prev = &node_pool[nodeCnt];

    return &node_pool[nodeCnt++];
}

static inline Node *get_tail(Node *head)
{
    return head->prev;
}

static inline void append2head(Node *n)
{
    n->prev = head;
    n->next = head->next;
    n->next->prev = n;
    n->prev->next = n;
}

static inline void append2tail(Node *n)
{
    Node *tail = get_tail(head);
    n->prev = tail;
    n->next = head;
    n->next->prev = n;
    n->prev->next = n;
}

static inline void insert(Node *piv, Node *n)
{
    if (piv == head)
        append2head(n);
    else if (piv == get_tail(head))
        append2tail(n);
    else
    {
        n->prev = piv;
        n->next = piv->next;
        n->next->prev = n;
        n->prev->next = n;
    }
    cursor = n;
}

static inline void remove(Node *n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;
}

void Init()
{
    nodeCnt = 0;
    head = alloc(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        Node *node = alloc(s[i]);
        append2tail(node);
    }
    cursor = get_tail(head);
}

void run()
{
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char cmd;
        cin >> cmd;
        char data;
        Node *node = new Node;
        switch (cmd)
        {
        case 'P':
            cin >> data;
            node = alloc(data);
            insert(cursor, node);
            break;

        case 'L':
            if(cursor != head)  cursor = cursor->prev;
            break;

        case 'D':
            if(cursor != get_tail(head)) cursor = cursor->next;
            break;

        case 'B':
            if(cursor != head) {
                remove(cursor);
                cursor = cursor->prev;
            }
            break;

        default:
            break;
        }
    }
}

void print()
{
    Node *cur = head;
    while (cur->next != head)
    {
        cout << cur->next->data;
        cur = cur->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    run();
    print();

    return 0;
}