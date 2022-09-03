#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 101

using namespace std;

struct Node {
    char data;
    int children[2];
};

Node node[MAX];
Node* root;
char text[MAX];
int textCnt;

void getNode(int num, char data, int left, int right) {
    node[num].data = data;
    node[num].children[0] = left;
    node[num].children[1] = right;
}

void Init() {
    root = new Node;
    textCnt = 0;
}

void make_tree(int N) {
    int num, left, right;
    char data;
    for(int i = 0; i < N; i++) {
        left = -1; right = -1;
        cin >> num >> data;
        if(cin.get() != '\n') {
            cin >> left;
            if(cin.get() != '\n') cin >> right;
        }

        getNode(num, data, left, right);
    }
}

void Inorder(int idx) {
    if(node[idx].children[0] != -1) Inorder(node[idx].children[0]);
    text[textCnt++] = node[idx].data;
    if(node[idx].children[1] != -1) Inorder(node[idx].children[1]);
}

void print(int N) {
    for(int i = 0; i < N; i++) {
        cout << text[i];
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
    fio;
    int test_case;
    int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin >> N;
        Init();
        make_tree(N);
        Inorder(1);
        
        cout << "#" << test_case << " ";
        print(N);
    }
    return 0;
}