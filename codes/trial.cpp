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
void createBinaryTree(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
    }
    if (val < root->val)
    {
        createBinaryTree(root->left, val);
    }
    else if (val > root->val)
    {
        createBinaryTree(root->right, val);
    }
}
/****************PRINT********************/
void print(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // part_1
        Node *p = q.front();
        q.pop();
        // part_2
        cout << p->val << " ";

        // part_3
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        createBinaryTree(root, val);
    }

    print(root);

    return 0;
}