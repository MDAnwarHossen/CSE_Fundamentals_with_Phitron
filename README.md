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
  
  ```
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
  
  ```
  int minimumValue = min(a, b);
  int maximumValue = max(a, b);
  ```
<h5>Among More Than Two Numbers:</h5>
  
  ```
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
  
  ```
  swap(a, b);
  ```
</details>
<details>
<summary>
  
## 1-8 String Input and Output in C++
</summary>
<p>cin object reads input until the next whitespace character (e.g., space, tab, or newline). To read an entire line of input, we can use getline()</p>
<h5>Syntax 1-</h5>
  
  ```
  char S[100];
  cin.getline(S, 100);
  ```
<h5>Syntax 2-</h5>
  
  ```
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
  
  ```
  int* dynamicArray = new int[size];
  ```
<h5>To Delete an array:</h5>
  
  ```
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
  
  ```
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
  
  ```
  delete[] myArray;
  ```
</details>
<details>
<summary>
  
## 3-5 Return Object from Function
</summary>
<p>Unlike returning an array, we don't need to make it dynamic. We can return an object from a function, even if it is a static object.</p>
<h3>Syntax for returning a static object:</h3>
  
  ```
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
  
  ```
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
  
  ```
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
  
# Header
</summary>
<p>
</details>
  
</blockquote></details>
