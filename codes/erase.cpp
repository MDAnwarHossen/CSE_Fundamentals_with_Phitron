#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> myList; // Creating a list
    // Add elements to the List
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    // Creating iterators of the list

    auto itr = myList.begin();

    // Incrementing itr by 3 positions
    advance(itr, 3);

    // deleting an elements from after pos 3
    myList.erase(itr);

    // Printing elements of list after deleting

    for (auto it = myList.begin();
         it != myList.end(); it++)
    {
        cout << *it << " "; // 10 20 30 50
    }
    cout << endl;

    // Delete multiple elements
    myList.erase(next(myList.begin(), 1), next(myList.begin(), 3));
    for (auto it = myList.begin();
         it != myList.end(); it++)
    {
        cout << *it << " "; // 10 50
    }
    cout << endl;

    return 0;
}
