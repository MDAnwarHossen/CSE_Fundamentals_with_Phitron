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

/***************************** SAMPLE INPUT & OUTPUT ***********************

 INPUT: 10 50 90 20 30 40M 80 70 60
 OUTPUT: 50 20 70 10 30 60 80 40 90

 ************************************************************************/

/********************* SORTED ARRAY TO BST ***************************/
Node *sortedArrayToBST(vector<int> v, int L, int R)
{
    if (L > R)
    {
        return NULL;
    }
    int mid = (L + R) / 2;
    Node *root = new Node(v[mid]);
    Node *leftRoot = sortedArrayToBST(v, L, mid - 1);
    Node *rightRoot = sortedArrayToBST(v, mid + 1, R);
    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}
/****************PRINT (Level Order Traversal) ********************/
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
/************************** MAIN FUNCTION******************************/
int main()
{
    vector<int> v = {10, 50, 90, 20, 30, 40, 80, 70, 60};
    sort(v.begin(), v.end()); // ascending order
    int R = v.size() - 1;
    Node *root = sortedArrayToBST(v, 0, R);
    print(root);

    return 0;
}