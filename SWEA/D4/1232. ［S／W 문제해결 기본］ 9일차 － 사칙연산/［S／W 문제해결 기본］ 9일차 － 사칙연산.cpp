#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1001
#define NUM 0
#define OP 1

using namespace std;

struct Node
{
    char op;
    double data = 0;
    int left = -1;
    int right = -1;
};

Node node_pool[MAX];

void getNode(int n, char op, int left, int right)
{
    node_pool[n].op = op;
    node_pool[n].data = 0;
    node_pool[n].left = left;
    node_pool[n].right = right;
}

void getNode(int n, double data)
{
    node_pool[n].data = data;
    node_pool[n].left = -1;
    node_pool[n].right = -1;
}

vector<string> tokenize_getline()
{
    vector<string> result;
    string s, token;
    getline(cin, s);
    stringstream ss(s);

    while (getline(ss, token, ' '))
    {
        result.push_back(token);
    }

    return result;
}

void make_tree(int N)
{
    string s;
    vector<string> v;

    for (int i = 0; i < N; i++)
    {
        v = tokenize_getline();
        if (v.size() > 2)
            getNode(stoi(v[0]), v[1][0], stoi(v[2]), stoi(v[3]));
        else
            getNode(stoi(v[0]), stod(v[1]));
    }
}

double Inorder(int idx)
{
    double left, right;

    if (node_pool[idx].left != -1) {
        left = Inorder(node_pool[idx].left);
        right = Inorder(node_pool[idx].right);
    }
    else return node_pool[idx].data;
    
    switch(node_pool[idx].op) {
        case '+' :
            return left + right;
        case '-' :
            return left - right;
        case '/' :
            return left / right;
        case '*' :
            return left * right;
    }
}

int main(int argc, char **argv)
{
    fio;
    int test_case;
    int T = 10;
    int N;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N; cin.ignore();
        make_tree(N);
        cout << "#" << test_case << " " << Inorder(1) << "\n";
    }
    return 0;
}