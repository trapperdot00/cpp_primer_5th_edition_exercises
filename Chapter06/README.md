# Chapter06: Functions
## [Exercise 6.1](6.01.txt)
What is the difference between a parameter and an argument?
## [Exercise 6.2](6.02.txt)
Indicate which of the following functions are in error and why. Suggest
how you might correct the problems.
```
(a) int f() {
        string s;
        // . . .
        return s;
    }
(b) f2(int i) { /* . . . */ }
(c) int calc(int v1, int v1) /* . . . */ }
(d) double square(double x) return x * x;
```
## [Exercise 6.3](6.03.cpp)
Write and test your own version of fact.
## [Exercise 6.4](6.04.cpp)
Write a function that interacts with the user, asking for a number and
generating the factorial of that number. Call this function from main.
## [Exercise 6.5](6.05.cpp)
Write a function to return the absolute value of its argument.
## [Exercise 6.6](6.06.txt)
Explain the differences between a parameter, a local variable, and a local
static variable. Give an example of a function in which each might be useful.
## [Exercise 6.7](6.07.cpp)
Write a function that returns 0 when it is first called and then generates
numbers in sequence each time it is called again.
## [Exercise 6.8](6.08)
Write a header file named Chapter6.h that contains declarations for
the functions you wrote for the exercises in § 6.1 (p. 205).
## [Exercise 6.9](6.09)
Write your own versions of the fact.cc and factMain.cc files. These
files should include your Chapter6.h from the exercises in the previous section. Use
these files to understand how your compiler supports separate compilation.
## [Exercise 6.10](6.10.cpp)
Using pointers, write a function to swap the values of two ints. Test
the function by calling it and printing the swapped values.
## [Exercise 6.11](6.11.cpp)
Write and test your own version of reset that takes a reference.
## [Exercise 6.12](6.12.cpp)
Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use refer-
ences instead of pointers to swap the value of two ints. Which version do you think
would be easier to use and why?
## [Exercise 6.13](6.13.txt)
Assuming T is the name of a type, explain the difference between a
function declared as void f(T) and void f(T&).
## [Exercise 6.14](6.14.txt)
Give an example of when a parameter should be a reference type. Give
an example of when a parameter should not be a reference.
## [Exercise 6.15](6.15.txt)
Explain the rationale for the type of each of find_char’s parameters
In particular, why is s a reference to const but occurs is a plain reference? Why are
these parameters references, but the char parameter c is not? What would happen if
we made s a plain reference? What if we made occurs a reference to const?
## [Exercise 6.16](6.16.txt)
The following function, although legal, is less useful than it might be.
Identify and correct the limitation on this function:
```
bool is_empty(string& s) { return s.empty(); }
```
## [Exercise 6.17](6.17.cpp)
Write a function to determine whether a string contains any capital
letters. Write a function to change a string to all lowercase. Do the parameters you
used in these functions have the same type? If so, why? If not, why not?
## [Exercise 6.18](6.18.h)
Write declarations for each of the following functions. When you write
these declarations, use the name of the function to indicate what the function does.
(a) A function named compare that returns a bool and has two parameters that
are references to a class named matrix.
(b) A function named change_val that returns a vector<int> iterator and
takes two parameters: One is an int and the other is an iterator for a vector<int>.
## [Exercise 6.19](6.19.txt)
Given the following declarations, determine which calls are legal and
which are illegal. For those that are illegal, explain why.
```
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", ’a’);
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```
## [Exercise 6.20](6.20.txt)
When should reference parameters be references to const? What hap-
pens if we make a parameter a plain reference when it could be a reference to const?
## [Exercise 6.21](6.21.txt)
Write a function that takes an int and a pointer to an int and returns
the larger of the int value or the value to which the pointer points. What type should
you use for the pointer?
## [Exercise 6.22](6.22.cpp)
Write a function to swap two int pointers.
## [Exercise 6.23](6.23.cpp)
Write your own versions of each of the print functions presented in
this section. Call each of these functions to print i and j defined as follows:
```
int i = 0, j[2] = {0, 1};
```
## [Exercise 6.24](6.24.txt)
Explain the behavior of the following function. If there are problems in
the code, explain what they are and how you might fix them.
```
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```
## [Exercise 6.25](6.25.cpp)
Write a main function that takes two arguments. Concatenate the sup-
plied arguments and print the resulting string.
## [Exercise 6.26](6.26.cpp)
Write a program that accepts the options presented in this section. Print
the values of the arguments passed to main.
## [Exercise 6.27](6.27.cpp)
Write a function that takes an initializer_list<int> and pro-
duces the sum of the elements in the list.
## [Exercise 6.28](6.28.txt)
In the second version of error_msg that has an ErrCode parameter,
what is the type of elem in the for loop?
## [Exercise 6.29](6.29.txt)
When you use an initializer_list in a range for would you ever
use a reference as the loop control variable? If so, why? If not, why not?
## [Exercise 6.30](6.30.cpp)
Compile the version of str_subrange as presented on page 223 to see
what your compiler does with the indicated errors.
## [Exercise 6.31](6.31.txt)
When is it valid to return a reference? A reference to const?
## [Exercise 6.32](6.32.txt)
Indicate whether the following function is legal. If so, explain what it
does; if not, correct any errors and then explain it.
```
int &get(int *arry, int index) { return arry[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```
## [Exercise 6.33](6.33.cpp)
Write a recursive function to print the contents of a vector.
## [Exercise 6.34](6.34.txt)
What would happen if the stopping condition in factorial were
```
if (val != 0)
```
## [Exercise 6.35](6.35.txt)
In the call to factorial, why did we pass val - 1 rather than val--?
## [Exercise 6.36](6.36.cpp)
Write the declaration for a function that returns a reference to an array
of ten strings, without using either a trailing return, decltype, or a type alias.
## [Exercise 6.37](6.37.cpp)
Write three additional declarations for the function in the previous ex-
ercise. One should use a type alias, one should use a trailing return, and the third
should use decltype. Which form do you prefer and why?
## [Exercise 6.38](6.38.cpp)
Revise the arrPtr function on to return a reference to the array.
## [Exercise 6.39](6.39.txt)
Explain the effect of the second declaration in each one of the following
sets of declarations. Indicate which, if any, are illegal.
```
(a) int calc(int, int);
    int calc(const int, const int);
(b) int get();
    double get();
(c) int *reset(int *);
    double *reset(double *);
```
## [Exercise 6.40](6.40.txt)
Which, if either, of the following declarations are errors? Why?
```
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);
```
## [Exercise 6.41](6.41.txt)
Which, if any, of the following calls are illegal? Why? Which, if any, are
legal but unlikely to match the programmer’s intent? Why?
```
char *init(int ht, int wd = 80, char bckgrnd = ’ ’);
(a) init();
(b) init(24,10);
(c) init(14, ’*’);
```
## [Exercise 6.42](6.42.cpp)
Give the second parameter of make_plural (§ 6.3.2, p. 224) a default
argument of ’s’. Test your program by printing singular and plural versions of the
words success and failure.
## [Exercise 6.43](6.43.txt)
Which one of the following declarations and definitions would you put
in a header? In a source file? Explain why.
```
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```
## [Exercise 6.44](6.44.h)
Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
## [Exercise 6.45](6.45.txt)
Review the programs you’ve written for the earlier exercises and decide
whether they should be defined as inline. If so, do so. If not, explain why they
should not be inline.
## [Exercise 6.46](6.46.txt)
Would it be possible to define isShorter as a constexpr? If so, do
so. If not, explain why not.
## [Exercise 6.47](6.47.cpp)
Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that
used recursion to print the contents of a vector to conditionally print information
about its execution. For example, you might print the size of the vector on each call.
Compile and run the program with debugging turned on and again with it turned off.
## [Exercise 6.48](6.48.txt)
Explain what this loop does and whether it is a good use of assert:
```
string s;
while (cin >> s && s != sought) { }  // empty body
assert(cin);
```
## [Exercise 6.49](6.49.txt)
What is a candidate function? What is a viable function?
## [Exercise 6.50](6.50.txt)
Given the declarations for f from page 242, list the viable functions, if
any for each of the following calls. Indicate which function is the best match, or if the
call is illegal whether there is no match or why the call is ambiguous.
```
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```
## [Exercise 6.51](6.51.cpp)
Write all four versions of f. Each function should print a distinguish-
ing message. Check your answers for the previous exercise. If your answers were
incorrect, study this section until you understand why your answers were wrong.
## [Exercise 6.52](6.52.txt)
Given the following declarations,
```
void manip(int, int);
double dobj;
```
what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?
```
(a) manip(’a’, ’z’);
(b) manip(55.4, dobj);
```
## [Exercise 6.53](6.53.txt)
Explain the effect of the second declaration in each one of the following
sets of declarations. Indicate which, if any, are illegal.
```
(a) int calc(int&, int&);
    int calc(const int&, const int&);
(b) int calc(char*, char*);
    int calc(const char*, const char*);
(c) int calc(char*, char*);
    int calc(char* const, char* const);
```
## [Exercise 6.54](6.54.txt)
Write a declaration for a function that takes two int parameters and
returns an int, and declare a vector whose elements have this function pointer type.
## [Exercise 6.55](6.55.cpp)
Write four functions that add, subtract, multiply, and divide two int
values. Store pointers to these functions in your vector from the previous exercise.
## [Exercise 6.56](6.56.txt)
Call each element in the vector and print their result.
