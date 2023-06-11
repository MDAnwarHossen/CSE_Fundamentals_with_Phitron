# CSE_Fundamentals_with_Phitron
<details><summary>Introduction to C++ for DSA</summary><blockquote>
  <details><summary>1-4 Setprecision in C++</summary><blockquote>
    Since a format specifier does not exist in C++, how can we set precision in a float value? For instance, If we want to shrink 2.568741 to 2.57, how can we do it?
    The method is as follows-
      
    float a;
    cin >> a;
    cout << fixed << setprecision(2) << a;
    
  </blockquote></details>
  <details><summary>1-6 min() and max() Built-in function in C++</summary><blockquote>
   In C++, the min() and max() functions can be used to find the minimum and maximum values between two or more variables. Here are two example usages:
    
   **For Two Numbers:**
    
    int minimumValue = min(a, b);
    int maximumValue = max(a, b);
   
   **For More Than Two Numbers:**
    
    int minimumValue = min({a, b, c});
    int maximumValue = max({a, b, c});
    
   Time Complexity - O(1)
    
  </blockquote></details>
    
  <details><summary>1-7 swap() Built-in Function in C++</summary><blockquote>
    The swap() function in C++ is used to exchange the values of two variables.
    Syntax-
      
    swap(a, b);
    
  </blockquote></details>
  <details><summary>1-8 String Input and Output in C++</summary><blockquote>
    cin object reads input until the next whitespace character (e.g., space, tab, or newline). To read an entire line of input, we can use getline()
    
   **Syntax 1-**
    
    char S[100];
    cin.getline(S, 100);
    
   **Syntax 2-**
    
    string S;
    getline(cin, S);
    
   It's important to note that getline() reads input until a newline character is encountered, but it discards the newline character itself. If you need to process the newline character, you can use ***cin.ignore()*** or handle it separately.
    
  </blockquote></details>
    
  <details><summary>2-3 Create Dynamic Array</summary><blockquote>
    To create a dynamic array in C++, we can use pointers and allocate memory on the heap using the new operator. Here's an example of creating a dynamic array:
      
    int* dynamicArray = new int[size];
    
  </blockquote></details>

  
</blockquote></details>
