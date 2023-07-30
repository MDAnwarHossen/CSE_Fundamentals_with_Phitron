#include <bits/stdc++.h>
using namespace std;
/********************* CREATE NODE *****************************/
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
/**************** SAMPLE INPUT & OUTPUT ********************

Input: 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Output: 1 3 4 6 7 8 10 13 14

********************************************************/

/************ CREATE BINARY SEARCH TREE (inputs are already sorted as Binary search tree) ********************/
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

/**************** PRINT (In Order Traversal) ********************/
void in_order_print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order_print(root->left);
    cout << root->val << " ";
    in_order_print(root->right);
}
/**************** MAIN FUNCTION ********************/
int main()
{
    Node *root = make_tree();
    in_order_print(root);

    return 0;
}