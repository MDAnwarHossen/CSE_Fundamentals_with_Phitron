#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
/*
Input: 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Output: 8 3 1 6 4 7 10 14 13
*/
Node *make_tree()
{
    int val;
    cin >> val;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int L, R;
        cin >> L >> R;
        Node *newLeft, *newRight;
        L == -1 ? newLeft = NULL : newLeft = new Node(L);
        R == -1 ? newRight = NULL : newRight = new Node(R);
        p->left = newLeft;
        p->right = newRight;
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}

/****************PRINT********************/
void pre_order_print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    pre_order_print(root->left);
    pre_order_print(root->right);
}

int main()
{
    Node *root = make_tree();
    pre_order_print(root);

    return 0;
}