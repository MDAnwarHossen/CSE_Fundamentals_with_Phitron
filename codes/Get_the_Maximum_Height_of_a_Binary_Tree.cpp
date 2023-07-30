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
/*********************************************************

Input: 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Output: 4

**********************************************************/

/**************CREATE BINARY SEARCH TREE (inputs are already sorted as Binary search tree)*******/
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

/************** Count Max Height of a Tree ****************/
int Max_Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int L = Max_Height(root->left);
    int R = Max_Height(root->right);
    return max(L, R) + 1;
}

/******************** MAIN FUNCTION************************/
int main()
{
    Node *root = make_tree();
    cout << Max_Height(root);

    return 0;
}