#include <bits/stdc++.h>
#define MAX_L 1000001

using namespace std;

struct Node
{
    char data;
    Node *next, *prev;
} node_pool[MAX_L];

Node *head;
Node *cursor;
int nodeCnt = 0;
int T;

static inline Node *alloc(char data)
{
    node_pool[nodeCnt].data = data;
    node_pool[nodeCnt].next = &node_pool[nodeCnt];
    node_pool[nodeCnt].prev = &node_pool[nodeCnt];

    return &node_pool[nodeCnt++];
}

static inline Node *get_tail()
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
    Node *tail = get_tail();
    n->prev = tail;
    n->next = head;
    n->next->prev = n;
    n->prev->next = n;
}

static inline void insert(Node *piv, Node *n)
{
    if (piv == head)
        append2head(n);
    else if (piv == get_tail())
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

static void init()
{
    nodeCnt = 0;
    head = alloc(0);
    cursor = head;
}

void print()
{
    Node *cur = head;
    while (cur->next != head)
    {
        cout << cur->next->data;
        cur = cur->next;
    }
    cout << "\n";
}

void run()
{
    string s;
    Node *node;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        init();
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            switch (s[j])
            {
            case '<':
                if (cursor != head)
                    cursor = cursor->prev;
                break;

            case '>':
                if (cursor != get_tail())
                    cursor = cursor->next;
                break;

            case '-':
                if(cursor != head) {
                    remove(cursor);
                    cursor = cursor->prev;
                }
                break;

            default:
                node = alloc(s[j]);
                insert(cursor, node);
                break;
            }
        }
        print();
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    run();

    return 0;
}