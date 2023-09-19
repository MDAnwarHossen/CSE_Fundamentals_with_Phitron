# CSE_Fundamentals_with_Phitron

<details>
<summary>
  
# Introduction to C++ for DSA
</summary><blockquote>
  
<details>
<summary>
  
## 1-4 Setprecision in C++
</summary>
<p>Since a format specifier does not exist in C++, how can we set precision in a float value? For instance, If we want to shrink 2.568741 to 2.57, how can we do it?</p>
<h5>The method is as follows-</h5>
  
  ```c++
  float a;
  cin >> a;
  cout << fixed << setprecision(2) << a;
  ```
</details>
<details>
<summary>
  
## 1-6 min() and max() Built-in function in C++
</summary>
<p>In C++, the min() and max() functions can be used to find the minimum and maximum values between two or more variables. Here are two example usages:</p>
<h5>Between Two Numbers:</h5>
  
  ```c++
  int minimumValue = min(a, b);
  int maximumValue = max(a, b);
  ```
<h5>Among More Than Two Numbers:</h5>
  
  ```c++
  int minimumValue = min({a, b, c});
  int maximumValue = max({a, b, c});
  ```
 <p>Time Complexity - O(1)</p>
</details>
<details>
<summary>
  
## 1-7 swap() Built-in Function in C++
</summary>
<p>The swap() function in C++ is used to exchange the values of two variables.</p>
<h5>Syntax-</h5>
  
  ```c++
  swap(a, b);
  ```
</details>
<details>
<summary>
  
## 1-8 String Input and Output in C++
</summary>
<p>cin object reads input until the next whitespace character (e.g., space, tab, or newline). To read an entire line of input, we can use getline()</p>
<h5>Syntax 1-</h5>
  
  ```c++
  char S[100];
  cin.getline(S, 100);
  ```
<h5>Syntax 2-</h5>
  
  ```c++
  string S;
  getline(cin, S);
  ```
<p>It's important to note that getline() reads input until a newline character is encountered, but it discards the newline character itself. If we need to process the newline character, we can use <strong>cin.ignore()</strong> or handle it separately.</p>
<p>Here is a problem we often face</p>
<img src="https://i.ibb.co/wpmN14J/Capture.png" alt="problem picture" style="width:400px;height:321px;">
<p>The reason we're not getting the desired value for string <strong>B</strong> is that when we use the <strong>getline(cin, B)</strong> function after reading an integer <strong>A</strong> using <strong>cin >> A</strong>, there is a newline character <strong>(\n)</strong> left in the input stream. The <strong>getline()</strong> function reads until it encounters a newline character, so it immediately reads that leftover newline character and assigns an empty string to <strong>B</strong>.</p>
<p>To fix this issue, we can add an extra <strong>cin.ignore()</strong> statement before the <strong>getline()</strong> function to discard the newline character. Here's the modified code:</p>
  
  ```c++
  #include <iostream>
  using namespace std;

int main() {
int A;
cin >> A;
cout << A << endl;

    cin.ignore(); // Add this line to discard the newline character

    string B;
    getline(cin, B);
    cout << B << endl;

    return 0;

}

````
</details>
<details>
<summary>

## 2-3 Create Dynamic Array
</summary>
<p>To create a dynamic array in C++, we can use pointers and allocate memory on the heap using the new operator. Here's an example of creating a dynamic array:</p>

```c++
int* dynamicArray = new int[size];
````

<h5>To Delete an array:</h5>
  
  ```c++
  delete[] dynamicArray;
  ```
</details>
<details>
<summary>
  
## 2-6 Return Dynamic Array from Function
</summary>
<p>It's important to note that directly returning a static array from a function is not possible because the lifetime of a static array is limited to the scope in which it is defined. This means that when a function finishes its work, the static array, along with all the variables declared inside it, will be deleted from the stack memory.</p>
<p>If we want to return an array from a function, we must have to make a dynamic array. Moreover, the return type of the function will be a pointer (*).</p>
<h5>Syntax below:</h5>
  
  ```c++
  int *dynamicArrayFun()
    {
      int *ary = new int[5];
      for (int i = 0; i < 5; i++)
      {
        ary[i] = i;
      }
    }
    int main()
    {
      int *myArray = dynamicArrayFun();
      return 0;
    }
  ```
<h5>To Delete an array:</h5>
  
  ```c++
  delete[] myArray;
  ```
</details>
<details>
<summary>
  
## 3-5 Return Object from Function
</summary>
<p>Unlike returning an array, we don't need to make it dynamic. We can return an object from a function, even if it is a static object.</p>
<h3>Syntax for returning a static object:</h3>
  
  ```c++
  class MyClass
    {
    public:
      int val_1;
      int val_2;
      MyClass(int val_1, int val_2)
      {
        this->val_1 = val_1;
        this->val_2 = val_2;
      }
    };
    MyClass myFun()
    {
      MyClass obj(5, 10);
      return obj;
    }
 int main()
   {
     MyClass obj = myFun();
     cout << obj.val_1 << " " << obj.val_2;
     return 0;
   }
  ```
<h3>Syntax for returning a dynamic object:</h3>
<p>To return a dynamic object, we can apply two approach</p>
<h5>Syntax 1 (Similar to the dynamic array method):</h5>
  
  ```c++
 class MyClass
  {
   public:
    int val_1;
    int val_2;
    MyClass(int val_1, int val_2)
     {
      this->val_1 = val_1;
      this->val_2 = val_2;
     }
   };

MyClass *myFun()
{
MyClass *dynamicObj = new MyClass(50, 100);
return dynamicObj;
}

int main()
{
MyClass \*obj = myFun();
cout << obj->val_1 << " " << obj->val_2;
return 0;
}

````
<h5>Syntax 2:</h5>

```c++
class MyClass
{
public:
    int val_1;
    int val_2;
    MyClass(int val_1, int val_2)
    {
        this->val_1 = val_1;
        this->val_2 = val_2;
    }
};

MyClass myFun()
{
    MyClass *dynamicObj = new MyClass(50, 100);
    return *dynamicObj;
}

int main()
{
    MyClass obj = myFun();
    cout << obj.val_1 << " " << obj.val_2;
    return 0;
}
````

</details>

<details>
<summary>
  
## 3-7 Access Values of Dynamic Object
</summary>
<p>To access the values of a dynamic object in C++, we need to use the arrow operator (->) with the pointer to the object.</p>
<h5>Syntax:</h5>
  
  ```c++
  MyClass* dynamicObj = new MyClass(50, 100);
  cout << dynamicObj->val_1 << " " << dynamicObj->val_2;
  ```
<p>There is an alternative approach, first we can dereferenced using the * operator to obtain the underlying object. Then, we can use the dot operator (.) to access the members of the object.</p>
<h5>Syntax:</h5>
  
  ```c++
  MyClass* dynamicObj = new MyClass(50, 100);
  cout << (*dynamicObj).val_1 << " " << (*dynamicObj).val_2;
  ```
</details>
<details>
<summary>
  
## 3-8 sort() Function in C++

</summary>
<h5>Sorting Syntax for Array:</h5>
  
  ```c++
  sort(a, a + n);
  ```
<h5>Sorting Syntax for String:</h5>
  
  ```c++
  sort(s.begin(), s.end());
  ```
<p>The sort() function in C++ is used to sort elements in a given range. It has three parts - <strong>start_iterator</strong>, <strong>end_iterator</strong> and <strong>comparison_operator</strong>. Comparison_operator is an optional parameter to specify the custom comparison function or predicate. If not provided, the default < operator is used for sorting in ascending order.</p>
<p>Bear in mind, When we call <strong>sort(a, a+n)</strong>, the range to be sorted includes the elements from <strong>a</strong> (inclusive) up to <strong>a+n</strong> (exclusive). In other words, the <strong>sort()</strong> function sorts the elements before the end iterator <strong>a + n</strong>. If we call <strong>sort(a, a+5)</strong>, it will sort before <strong>a+5</strong></p>
<h5>Here is a picture for better understanding</h5>
<img src="https://i.ibb.co/9T2d7Rq/Capture.png" alt="Sort picture" style="width:500px;height:142px;">
<p><strong>Time complexity: </strong> Time complexity of <strong>sort()</strong> function is <strong>O(N log N)</strong>, which is better than <strong>selection sort</strong></p>
</details>
<details>
<summary>
  
## 5-1 String in C++
</summary>
<p>Source link: https://cplusplus.com/reference/string/string/</p>
<h5>Capacity:</h5>
  <ul>
    <li><strong>s.size()</strong> -> returns the size of the string.</li>
    <li><strong>s.max_size()</strong> -> returns the maximum size that string can hold.</li>
    <li><strong>s.capacity()</strong> -> returns current available capacity of the string.</li>
    <li><strong>s.clear()</strong> -> clear the string.</li>
    <li><strong>s.empty()</strong> -> return true/false if the string is empty.</li>
    <li><strong>s.resize(new_size, fill_char)</strong> -> change the size of the string.</li>
  </ul>
<h5>Element access:</h5>
  <ul>
    <li><strong>S[i]</strong> -> access the ith index of the string.</li>
    <li><strong>s.at(i)</strong> -> access the ith index of the string.</li>
    <li><strong>s.back()</strong> -> access the last element of the string.</li>
    <li><strong>s.front()</strong> -> access the first element of the string.</li>
  </ul>
 <h5>Modifiers:</h5>
  <ul>
    <li><strong>s+=</strong> -> append another string.</li>
    <li><strong>s.append("Hello")</strong> -> to append different strings to s. Each call to append() adds the specified string to the end of s</li>
    <li><strong>s.push_back("H")</strong> -> add character to the last of the string.</li>
    <li><strong>s.pop_back()</strong> -> remove the last character of the string.</li>
    <li><strong>s=</strong> -> assign string.</li>
    <li><strong>s.assign("Goodbye")</strong> -> assign string.</li>
    <li><strong>s.erase(5)</strong> -> erase characters from the string.</li>
    <li><strong>s.replace(6, 5, "C++")</strong> -> replace a portion of the string.</li>
    <li><strong>s.insert(6, "C++ ")</strong> -> insert a portion to a specific position.</li>
  </ul>
  <h5>Iterators:</h5>
  <ul>
    <li><strong>s.begin()</strong> -> pointer to the first element.</li>
    <li><strong>s.end()</strong> -> pointer to the next element after the last element of the string.</li>
</details>
<details>
<summary>
  
## 5-8 Stringstream in C++
</summary>
<p>Stringstream provides a convenient way to extract values from strings or concatenate values into a string.</p>
<h5>To extract values from strings:</h5>
  
  ```c++
    string sentence = "Hello world!";
    stringstream ss(sentence); // Create a stringstream object with the sentence string

    string word;
    while (ss >> word)
    {
        cout << word << endl; // Output each extracted word
    }

````
<h5>To concatenate values into a string:</h5>

```c++
  string word_1 = "Hello";
  string word_2 = "world!";

  stringstream ss;
  ss << word_1 << " " << word_2;
  string result = ss.str();
  cout << result << endl;
````

</details>
<details>
<summary>
  
## 6-3 Range Based For Loop in String
</summary>
<p>The range-based for loop is a convenient loop construct that simplifies iterating over elements in a container or range.</p>
<h5>Syntax:</h5>
  
  ```c++
    string myString = "Hello world";
    for (char c : myString)
    {
        cout << c << " ";
    }
  ```
</details>
<details>
<summary>
  
## 6-4 Reverse Word Printing using Stringstream
</summary>
<p>অনেক informative একটা ভিডিও I এটা নিয়ে পরে কাজ করবো I pass by value and pass by reference নিয়ে আরেকটা সেকশন করতে হবে I যেটা C তে মডিউল ১৫ তে দেখাইছিলো </p>
</details>
<details>
<summary>
  
## 6-6 This Keyword in C++
</summary>
<p>The keyword "this" is a pointer that refers to the current object instance within a member function of a class. It is an implicit parameter that allows us to access the object's members and distinguish them from local variables or parameters with the same name.</p>

```c++
   class MyClass
   {
    public:
      string name;
      int age;
      MyClass(string name, int age)
      {
        this->name = name;
        this->age = age;
      }
};
int main()
{
    MyClass myObj("Rohim", 15);
    return 0;
}
```

</details>
<details>
<summary>
  
## 7-5 Sort Array of Objects using sort() Function
</summary>
<p>The sort() function allows us to provide a custom comparison function to define the sorting order. The comparison function should be a binary predicate that takes two arguments and returns true if the first argument should be placed before the second argument in the sorted sequence.</p>
<h5>Example:</h5>

```c++
#include <bits/stdc++.h>
using namespace std;

class MyClass
{
public:
    string name;
    int age;
    MyClass(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
bool comparison_function(MyClass a, MyClass b)
{
    // Sorting in descending order
    return a.age > b.age;
}
int main()
{
    MyClass person_1("Rohim", 15);
    MyClass person_2("Korim", 25);
    MyClass person_3("Hafiz", 50);
    MyClass person_4("Tabeeb", 12);
    vector<MyClass> ary = {person_1, person_2, person_3, person_4};

    sort(ary.begin(), ary.end(), comparison_function);

    for (MyClass person : ary)
    {
        cout << person.name << " " << person.age << endl;
    }
    return 0;
}
```

</details>

<details>
<summary>
  
## End
</summary>
<p>
</details>
  
</blockquote></details>

<details>
<summary>
  
# Basic Data Structures
</summary><blockquote>

<details>
<summary>
  
## 1-1 What is Time Complexity
</summary>
<p>Time complexity is defined as the amount of time taken by an algorithm to run. It measures the time taken to execute each statement of code in an algorithm</p>
<h5>Input limit of Time Complexity</h5>
<table>
  <tr>
    <th>Big O notation</th>
    <th>Known As</th>
    <th>Input size</th>
    <th>Example</th>
  </tr>
  <tr>
    <td>O(1)</td>
    <td>Constant Time Complexity</td>
    <td></td>
    <td></td>
  </tr>
   <tr>
    <td>O(log N)</td>
    <td>Logarithmic Time Complexity</td>
     <td>10<sup>18</sup></td>
     <td>Binary search, binary heaps, merge sort, and quicksort</td>
  </tr>
  <tr>
    <td>O($\sqrt{N}$)</td>
    <td>Square Root Time Complexity</td>
     <td>10<sup>14</sup></td>
    <td>Checking perfect square, Checking prime numbe</td>
  </tr>
  <tr>
    <td>O(N)</td>
    <td>Linear Time Complexity</td>
     <td>10<sup>7</sup></td>
    <td>Arrays, Linked Lists, Linear Search, Bubble Sort, Selection Sort, Counting Sort</td>
  </tr>
  <tr>
    <td>O(N log(N))</td>
    <td>Linearithmic Time Complexity</td>
     <td>10<sup>5</sup></td>
    <td>Merge Sort, QuickSort, Heap Sort</td>
  </tr>
  <tr>
    <td>O(N*N)</td>
    <td>Quadratic Time Complexity</td>
     <td>10<sup>3</sup></td>
    <td>Bubble Sort, Selection Sort, Insertion Sort</td>
  </tr>
</table>
</details>

<details>
<summary>
  
## 1-8 What is Space Complexity
</summary>
<p>The space Complexity of an algorithm is the total space taken by the algorithm with respect to the input size. Space complexity includes both Auxiliary space and space used by input. Auxiliary Space is the extra space or temporary space used by an algorithm.</p>

</details>

<details>
<summary>
  
## STL Vector
</summary>
<h4>1. Constructor</h4>
<table>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>vector<'type'>v</td>
    <td>Construct a vector with 0 elements</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>vector<'type'>v(N)</td>
    <td>Construct a vector with N elements and the value will be garbage</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>vector<'type'>v(N,V)</td>
    <td>Construct a vector with N elements and the value will be V</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>vector<'type'>v(v2)</td>
    <td>Construct a vector by copying another vector v2</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>vector<'type'>v(A,A+N)</td>
    <td>Construct a vector by copying all elements from an array A of size N</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>vector<'vector<'type''>> v(m, vector<'type'>(n))</td>
    <td>create a 2D vector with 'm' rows and 'n' columns, initialized with a default value for each element.</td>
    <td>O(N*N)</td>
  </tr>
</table>
<h4>2. Capacity</h4>
<table>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>v.size()</td>
    <td>Returns the size of the vector</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.max_size()</td>
    <td>Returns the maximum size that the vector can hold</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.capacity()</td>
    <td>Returns the current available capacity of the vector</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.clear()</td>
    <td>Clears the vector elements. Do not delete the memory, only clear the value.</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>v.empty()</td>
    <td>Return true/false if the vector is empty or not.</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.resize()</td>
    <td>Change the size of the vector</td>
    <td>O(K); where K is the difference between new size and current size</td>
  </tr>
</table>
<h4>3. Modifiers</h4>
<table>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>v= or v.assign()</td>
    <td>Assign another vector</td>
    <td>O(N) if sizes are different, O(1) otherwise</td>
  </tr>
  <tr>
    <td>v.push_back()</td>
    <td>Add an element to the end</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.pop_back()</td>
    <td>Remove the last element</td>
    <td>O(1)</td>
  </tr>
  <tr>
    <td>v.insert()</td>
    <td>Insert elements at a specific position</td>
    <td>O(N+K); where K is the number of elements to be inserted</td>
  </tr>
  <tr>
    <td>v.erase()</td>
    <td>Delete elements from a specific position</td>
    <td>O(N+K); where K is the number of elements to be deleted</td>
  </tr>
  <tr>
    <td>replace(v.begin(),v.end(),value,replace_value)</td>
    <td>Replace all the value with replace_value. Not under a vector</td>
    <td>O(N)</td>
  </tr>
  <tr>
    <td>find(v.begin(),v.end(),V)</td>
    <td>Find the value V. Not under a vector</td>
    <td>O(N)</td>
  </tr>
</table>
<h4>4. Element access</h4>
<table width=100>
<tbody width=100>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>v[i]</td>
    <td>Access the ith element.</td>
    <td>O(1)</td>
  </tr>
 <tr>
    <td>v.at(i)</td>
    <td>Access the ith element.</td>
    <td>O(1)</td>
  </tr>
   <tr>
    <td>v.back()</td>
    <td>Access the last element</td>
    <td>O(1)</td>
  </tr>
   <tr>
    <td>v.front()</td>
    <td>Access the first element</td>
    <td>O(1)</td>
  </tr>
  <tbody>
</table>
<h4>5. Iterators</h4>
<table>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>v.begin()</td>
    <td>Pointer to the first element.</td>
    <td>O(1)</td>
  </tr>
 <tr>
    <td>v.end()</td>
    <td>Pointer to the last element</td>
    <td>O(1)</td>
  </tr> 
</table>
</details>
<details>
<summary>
  
## 3-2 Idea of Prefix Sum Array
</summary>
<h5>What is Prefix Sum</h5>
<p>Prefix Sum, also known as Cumulative Sum, is a technique used in computer science and mathematics to efficiently calculate the running sum of elements in an array or sequence. The idea behind prefix sum is to precompute and store the cumulative sum of elements up to each index in the array.</p>

<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/prefix_Sum.jpg">
<p>The idea is that, While traversing an array, update the element by adding it with its previous element. As a result, we would be able to get a summation from any index to any index.</p>
<p>For example, if we want to obtain the summation from index 1 to index 3 of the above picture, we would be able to get it easily.</p>

```c++
A[3] - A[1-1];
```

<h5>Corner case:</h5>
<p>If we want to obtain the summation from any index to the 0 index, we don't need to subtract A[0-1] because we can't go beyond 0.</p>
</details>
<details>
<summary>
  
## 3-5 Idea of Binary Search Algorithm
</summary>
<h5>What is Binary Search Algorithm?</h5>
<p>Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N). </p>

<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/binary-search.jpg">
<h5>In this algorithm</h5>

    + Divide the search space into two halves by finding the middle index “mid”.
    + Compare the middle element of the search space with the key.
    + If the key is found at middle element, the process is terminated.
    + If the key is not found at middle element, choose which half will be used as the next search space.

      + If the key is smaller than the middle element, then the left side is used for next search.
      + If the key is larger than the middle element, then the right side is used for next search.

    + This process is continued until the key is found or the total search space is exhausted.

</details>

<details>
<summary>
  
## 5-1 Why Linked List - I
</summary>
<h5>What is Linked List?</h5>
<p>Linked lists are linear data structures that hold data in individual objects called nodes. These nodes hold both the data and a reference to the next node in the list</p>

<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/LLdrawio.png">
<h5>Why do we need linked lists?</h5>
<ul>
<li>Efficient Insertions and Deletions</li>
<li>Flexible Memory Allocation</li>
<li>Easy Merge and Split</li>
<li>Dynamic Size</li>
</ul>

</details>
<details>
<summary>
  
## Module 10: STL List and Cycle Detection
</summary>
<h5>1. Constructor</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <td>list<'type'>myList</td>
  <td>Construct a list with 0 elements</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>list<'type'>myList(N)</td>
  <td>Construct a list with N elements and the value will be garbage</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>list<'type'>myList(N,V)</td>
  <td>Construct a list with N elements and the value will be V</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>list<'type'>myList(list2)</td>
  <td>Construct a list by copying another list list2</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>list<'type'>myList(A,A+N)</td>
  <td>Construct a list by copying all elements from an array A of size N</td>
  <td>O(N)</td>
</tr>
</table>
<h5>2. Capacity</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <td>myList.size()</td>
  <td>Returns the size of the list</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.empty()</td>
  <td>Return true/false if the list is empty or not.</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.max_size()</td>
  <td>Returns the maximum size that the vector can hold</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.clear()</td>
  <td>Clears the list elements. Do not delete the memory, only clear the list.</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>myList.resize(v)</td>
  <td>Change the size of the list</td>
  <td>O(v); where v is the difference between new size and current size.</td>
</tr>
</table>
<h5>3. Modifiers</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <td>myList= or myList.assign(list2.begin(),list2.end())</td>
  <td>Assign another list.</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>myList.push_back(val)</td>
  <td>Add an element to the tail</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.push_front(val)</td>
  <td>Add an element to the head.</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.pop_back()</td>
  <td>Delete the tail.</td>
  <td>O(1)</td>
</tr>
<tr>
  <td>myList.pop_front()</td>
  <td>Delete the head.</td>
  <td>O(1)</td>
</tr>
<tr>
  <td><img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/red.png">myList.insert(pos, val)
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/myList_insert.cpp" target="_blank"> See Code </a></td>

  <td>Insert elements at a specific position.</td>
  <td>O(N+K); where K is the number of elements to be inserted.</td>
</tr>
<tr>
  <td>myList.insert(pos,Num_of_ele_to_insert, val) <a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/myList_insert.cpp" target="_blank"> See Code </a></td>
  <td>Insert elements at a specific position.</td>
  <td>O(N+K); where K is the number of elements to be inserted.</td>
</tr>
<tr>
  <td>myList.erase(iterator_position)<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/erase.cpp" target="_blank"> See Code </a></td>
  <td>Delete elements from a specific position.</td>
  <td>O(N+K); where K is the number of elements to be deleted.</td>
</tr>
<tr>
  <td>myList.erase(iterator_pos, iterator_pos) <a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/erase.cpp" target="_blank"> See Code </a></td>
  <td>Delete elements from a specific position.</td>
  <td>O(N+K); where K is the number of elements to be deleted.</td>
</tr>
<tr>
  <td>replace(myList.begin(),myList.end(),value,replace_value)</td>
  <td>Replace all the value with replace_value. Not under a list STL.</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>find(myList.begin(),myList.end(),V)</td>
  <td>Find the value V. Not under a list STL.</td>
  <td>O(N)</td>
</tr>
</table>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/red.png">
There are two methods to traverse to a specific position in a linked list.
<h5>Method 1</h5>

```c++
auto pos = myList.begin();  // create a iterator to beginning
advance(pos, 2);            //Go to that pos. Here pos 2. Means after 2 pos
myList.insert(pos, 5);      // inserts 5 at 3rd position
```

<h5>Method 2</h5>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Capture.PNG">
<h5>4. Operations</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <td>myList.sort()</td>
  <td>Sort the list in ascending order.</td>
  <td>O(NlogN)</td>
</tr>
<tr>
  <td>myList.sort(greater<type>())</td>
  <td>Sort the list in descending order</td>
  <td>O(NlogN)</td>
</tr>
<tr>
  <td>myList.reverse()</td>
  <td>Reverse the list.</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>myList.remove(V)</td>
  <td>Remove the value V from the list.</td>
  <td>O(N)</td>
</tr>
<tr>
  <td>myList.unique()</td>
  <td>Deletes the duplicate values from the list. You must sort the list first.</td>
  <td>O(N), with sort O(NlogN)</td>
</tr>
</table>
<h5>5. Element access</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
<td>myList.back()</td>
<td>Access the tail element.</td>
<td>O(1)</td>
</tr>
<tr>
<td>myList.front()</td>
<td>Access the head element.</td>
<td>O(1)</td>
</tr>
<tr>
<td>next(myList.begin(),i)</td>
<td>Access the ith element</td>
<td>O(1)</td>
</tr>
</table>
<h5>6. Iterators</h5>
<table>
<tr>
  <th>Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
<td>myList.begin()</td>
<td>Pointer to the first element.</td>
<td>O(1)</td>
</tr>
<tr>
<td>myList.end()</td>
<td>Pointer to the last element.</td>
<td>O(1)</td>
</tr>
</table>
</details>
<details>
<summary>
  
## 10-8 Detect Cycle in Singly Linked List
</summary>
<h5>Detect loop in a linked list using Floyd’s Cycle-Finding Algorithm</h5>
<p>This algorithm is used to find a loop in a linked list. It uses two pointers. Move one pointer(slow_p) by one and another pointer(fast_p) by two. The faster one is called the faster pointer(fast_p) and the other one is called the slow pointer(slow_p).</p>
<p>If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.</p>
<h5>Illustration:</h5>
<p>The below image shows how the detect loop function works in the code:</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Detect-loop-in-a-linked-list.png">
<h5>Here is the implementation of the above approach.</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Linked_List_Cycle.cpp" target="_blank"> See Code </a>

</details>
<details>
<summary>
  
## 13-3 What is Stack
</summary>
<p>A "stack" is a data structure that operates on a last-in, first-out (LIFO) basis. It is a collection of elements where elements are added and removed from the same end, known as the "top" of the stack. The last element added to the stack will be the first one to be removed.</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Stack-Data-Structure.png">
<h5>The method functions associated with stack are:</h5>
<table>
<tr>
  <th>Function Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <th>st.empty()</th>
  <th>Returns whether the stack is empty</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>st.size()</th>
  <th>Returns the size of the stack</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>st.top()</th>
  <th>Returns a reference to the top most element of the stack</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>st.push(val)</th>
  <th>Adds the element ‘val’ at the top of the stack</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>st.pop()</th>
  <th>Deletes the most recent entered element of the stack</th>
  <th>O(1)</th>
</tr>
</table>
</details>
<details>
<summary>
  
## What is Queue
</summary>
<p>A "queue" is a data structure that operates on a first-in, first-out (FIFO) basis. It is a collection of elements where elements are added at the rear (also called the "enqueue"(or Push) operation) and removed from the front (also called the "dequeue"(or Pop) operation).</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Queue-Data-structure1.png">
<h5>The method functions associated with queue are:</h5>
<table>
<tr>
  <th>Function Name</th>
  <th>Details</th>
  <th>Time Complexity</th>
</tr>
<tr>
  <th>q.empty()</th>
  <th>Returns whether the queue is empty. It return true if the queue is empty otherwise returns false.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.size()</th>
  <th>Returns the size of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.push(val)</th>
  <th>Adds the element ‘val’ at the end of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.pop() </th>
  <th>Deletes the first element of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.front() </th>
  <th>Returns a reference to the first element of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.back() </th>
  <th>Returns a reference to the last element of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.emplace() </th>
  <th>Insert a new element into the queue container, the new element is added to the end of the queue.</th>
  <th>O(1)</th>
</tr>
<tr>
  <th>q.swap() </th>
  <th>Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.</th>
  <th>O(1)</th>
</tr>
</table>
</details>
<details>
<summary>
  
## 17-3 Discussion about Binary Tree
</summary>
<p>A binary tree is a tree-type non-linear data structure with a maximum of two children for each parent. Every node in a binary tree has a left and right reference along with the data element. The node at the top of the hierarchy of a tree is called the root node.</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Binary_Tree.PNG">
<h5>Applications of Binary Tree:</h5>
<ul>
<li>Binary tree can be used in a searching algorithms such as 'Binary search' which can be used to quickly find an element in a sorted list.</li>
<li>Binary trees can be used to implement sorting algorithms, such as in heap sort which uses a binary heap to sort elements efficiently.</li>
<li>Binary trees can be used in machine learning algorithms or AI. They provide a decision-making process that is done through the binary tree structure.</li>
<li>There is a Syntax tree in a compiler which done through binary tree</li>
</ul>

</details>
<details>
<summary>
  
## 17-4 Create a Binary Tree
</summary>
<p>To create a Binary Tree we will use a breadth-first traversal (level-order traversal) instead of a recursive approach for insertion.</p>
<h5>If the inputs are already sorted as Binary search tree:</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/insertIntoBinaryTree.cpp" target="_blank"> See Code </a>
<h5>Convert sorted array/numbers to Binary search tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/convert_array_to_BST.cpp" target="_blank"> See Code </a>

</details>

<details>
<summary>
  
## Traversal of Binary Tree
</summary>
<h5>Pre Order Traversal of Binary Tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Pre_Order_Traversal.cpp" target="_blank"> See Code </a>
<h5>Post Order Traversal of Binary Tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Post_Order_Traversal.cpp" target="_blank"> See Code </a>
<h5>In Order Traversal of Binary Tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/in_Order_Traversal.cpp" target="_blank"> See Code </a>
<h5>Level Order Traversal of Binary Tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/insertIntoBinaryTree.cpp" target="_blank"> See Code </a>

</details>
<details>
<summary>
  
## 18-5 Count Number of Nodes in a Binary Tree
</summary>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Count_Number_of_Nodes_in_a_Binary_Tree.cpp" target="_blank"> See Code </a>
</details>
<details>
<summary>
  
## 18-6 Count Number of Leaf Nodes in a Binary Tree
</summary>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Count_Number_of_Leaf_Nodes_in_a_Binary_Tree.cpp" target="_blank"> See Code </a>
</details>
<details>
<summary>
  
## 18-7 Get the Maximum Height of a Binary Tree
</summary>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/Get_the_Maximum_Height_of_a_Binary_Tree.cpp" target="_blank"> See Code </a>
</details>
<details>
<summary>
  
## 21-1 What is BST (Binary Search Tree)
</summary>
<p>A Binary Search Tree (BST) is a specialized form of a binary tree data structure that follows some order to arrange the elements. The properties that separate a binary search tree from a regular binary tree is- </p>
<ul>
<li>All nodes of left subtree are less than the root node</li>
<li>All nodes of right subtree are more than the root node</li>
</ul>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/bst.jpeg">
<p>The binary tree on the right isn't a binary search tree because the right subtree of the node "3" contains a value smaller than it.</p>
<h5>If the inputs are already sorted as Binary search tree:</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/insertIntoBinaryTree.cpp" target="_blank"> See Code </a>
<h5>Convert sorted array/numbers to Binary search tree</h5>
<a href="https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/codes/convert_array_to_BST.cpp" target="_blank"> See Code </a>
</details>
<details>
<summary>
  
## 22-1 What is Complete Binary Tree

</summary>
<p>A complete binary tree is a special type of binary tree where all the levels of the tree are filled completely except the lowest level nodes which are filled from as left as possible. </p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/complete_binary_1.jpg">
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/complete_binary_2.jpg">
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Complete-Binary-Tree.png">

</details>

<details>
<summary>
  
## 22-2 Array Representation of Complete Binary Tree

</summary>
<p>Here's how you can represent a complete binary tree as an array:</p>
<ul>
<li>Root of the tree is stored at index 0.</li>
<li>For any node at index i, its left child is at index i*2 + 1, and its right child is at index i*2 + 2.</li>
<li>For any node at index i, its parent is at index (i - 1) / 2, where / represents integer division (floor division).</li>
</ul>
<p>Here's a visual representation of how this works for a small complete binary tree:</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/Complete_Binary_Tree_to_array.PNG">
</details>

<details>
<summary>
  
## 22-3 What is Heap

</summary>
<p>A Heap is a special Tree-based data structure in which the tree is a complete binary tree.</p>
<p>There are two common types of heaps: the min-heap and the max-heap.</p>
<img src = "https://github.com/MDAnwarHossen/CSE_Fundamentals_with_Phitron/blob/main/images/MinHeapAndMaxHeap1.png">

<table>
  <tr>
    <th>Name</th>
    <th>Details</th>
    <th>Time Complexity</th>
  </tr>
  <tr>
    <td>make_heap(array.begin(), array.end())</td>
    <td>We can use make_heap() function to create a max heap from an array. This function will rearrange an array into a valid heap</td>
    <td>O(nlogn)</td>
  </tr>
  <tr>
    <td>make_heap(numbers.begin(), numbers.end(), greater<int>())</td>
    <td>As same as previous function. But this will create a min heap because of comparison function</td>
    <td>O(nlogn)</td>
  </tr>
  <tr>
    <td>push_heap(array.begin(), array.end())</td>
    <td>If the array is already a heap array, we have just inputted one new element at the end of the array. We can use push_heap() instead of make_heap() function.</td>
    <td>O(logn)</td>
  </tr>
  <tr>
    <td>pop_heap(array.begin(), array.end())</td>
    <td>Remove the root element (minimum or maximum, depending on the heap type) from the heap while maintaining the heap property. This function will remove and place the root element at the end of the array. To remove it from the array we have to use array.pop_back() function</td>
    <td>O(logn)</td>
  </tr>
  <tr>
    <td>is_heap(array.begin(), array.end())</td>
    <td>is_heap() function is used to check whether the given range of the array is a heap or not. By default, it checks for max heap but we can also use a comparator to make it work for min heap.</td>
    <td>O(n)</td>
  </tr>
  </table>

</details>

</blockquote></details>
</blockquote></details>

```

```
