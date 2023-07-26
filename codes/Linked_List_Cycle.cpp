#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    //[1,2,3,4,5]
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);
    ListNode *e = new ListNode(6);

    // connection
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;

    ListNode *fast_p = head;
    ListNode *slow_p = head;

    int flag = 0;
    while (fast_p != NULL && fast_p->next != NULL)
    {
        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
        if (fast_p == slow_p)
        {
            flag = 1;
            break;
        }
    }
    flag ? cout << "Cycle Detected" : cout << "Cycle NOT Detected";
    return 0;
}