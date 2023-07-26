#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> demoList; // Creating a list
    // Add elements to the List
    demoList.push_back(10);
    demoList.push_back(20);
    demoList.push_back(30);
    demoList.push_back(40);
    demoList.push_back(50);

    // Creating iterators of the list

    auto itr = demoList.begin();

    // Incrementing itr2 by 3 positions
    advance(itr, 3);

    // deleting range of elements from index [0, 3)
    demoList.erase(itr);

    // Printing elements of list after deleting

    for (auto it = demoList.begin();
         it != demoList.end(); it++)
    {
        cout << *it << " "; // 10 20 30 50
    }

    return 0;
}
