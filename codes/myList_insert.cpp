#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> myList;          // declaring list
    myList.assign(3, 2);       // creates 2 2 2 nodes to the list
    auto pos = myList.begin(); // create a iterator to beginning
    advance(pos, 2);           // Go to that position. Here after 2 position. That means 3rd position.
    myList.insert(pos, 5);     // inserts 5 at 3rd position
    for (auto i = myList.begin(); i != myList.end(); i++)
    {
        cout << *i << " "; // 2 2 5 2
    }
    cout << endl;

    // insert multiple value
    pos = myList.begin();
    advance(pos, 3);
    myList.insert(pos, 2, 7); // inserts 7 7 at 4th & 5th position
    for (auto i = myList.begin(); i != myList.end(); i++)
    {
        cout << *i << " "; // 2 2 5 7 7 2
    }
    return 0;
}