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
<p>It's important to note that getline() reads input until a newline character is encountered, but it discards the newline character itself. If you need to process the newline character, you can use <strong>cin.ignore()</strong> or handle it separately.</p>
</details>
<details>
<summary>
  
## 2-3 Create Dynamic Array
</summary>
<p>To create a dynamic array in C++, we can use pointers and allocate memory on the heap using the new operator. Here's an example of creating a dynamic array:</p>
  
  ```c++
  int* dynamicArray = new int[size];
  ```
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
      MyClass *obj = myFun();
      cout << obj->val_1 << " " << obj->val_2;
      return 0;
   }
  ```
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
  ```
  
</details>

<details>
<summary>
  
## 3-7 Access Values of Dynamic Object
</summary>
<p>To access the values of a dynamic object in C++, you need to use the arrow operator (->) with the pointer to the object.</p>
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
<h5>Basic Syntax:</h5>
  
  ```c++
  sort(a, a + n);
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
</details>
<details>
<summary>
  
## Header
</summary>
<p>
</details>
  
  
<details>
<summary>
  
# Header
</summary>
<p>
</details>
  
</blockquote></details>
