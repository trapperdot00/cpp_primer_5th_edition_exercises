# Chapter02: Variables and Basic Types
## [Exercise 2.1](Chapter02/2.01.txt)
What are the differences between int, long, long long, and short?
Between an unsigned and a signed type? Between a float and a double?
## [Exercise 2.2](Chapter02/2.02.txt)
To calculate a mortgage payment, what types would you use for the rate,
principal, and payment? Explain why you selected each type.
## [Exercise 2.3](Chapter02/2.03.txt)
What output will the following code produce?
```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```
## [Exercise 2.4](Chapter02/2.04.cpp)
Write a program to check whether your predictions were correct. If not,
study this section until you understand what the problem is.
## [Exercise 2.5](Chapter02/2.05.txt)
Determine the type of each of the following literals. Explain the differ-
ences among the literals in each of the four examples:
```
(a) ’a’, L’a’, "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```
## [Exercise 2.6](Chapter02/2.06.txt)
What, if any, are the differences between the following definitions:
```
int month = 9, day = 7;
int month = 09, day = 07;
```
## [Exercise 2.7](Chapter02/2.07.txt)
What values do these literals represent? What type does each have?
```
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```
## [Exercise 2.8](Chapter02/2.08.cpp)
Using escape sequences, write a program to print 2M followed by a new-
line. Modify the program to print 2, then a tab, then an M, followed by a newline.
## [Exercise 2.9](Chapter02/2.09.cpp)
Explain the following definitions. For those that are illegal, explain
what’s wrong and how to correct it.
```
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```
## [Exercise 2.10](Chapter02/2.10.cpp)
What are the initial values, if any, of each of the following variables?
```
std::string global_str;
int global_int;
int main()
{
  int local_int;
  std::string local_str;
}
```
## [Exercise 2.11](Chapter02/2.11.cpp)
Explain whether each of the following is a declaration or a definition:
```
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;
```
## [Exercise 2.12](Chapter02/2.12.cpp)
Exercise 2.12: Which, if any, of the following names are invalid?
```
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;
```
## [Exercise 2.13](Chapter02/2.13.cpp)
What is the value of j in the following program?
```
int i = 42;
int main()
{
  int i = 100;
  int j = i;
}
```
## [Exercise 2.14](Chapter02/2.14.cpp)
Is the following program legal? If so, what values are printed?
```
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
  sum += i;
std::cout << i << " " << sum << std::endl;
```
## [Exercise 2.15](Chapter02/2.15.cpp)
Which of the following definitions, if any, are invalid? Why?
```
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```
## [Exercise 2.16](Chapter02/2.16.cpp)
Which, if any, of the following assignments are invalid? If they are
valid, explain what they do.
```
int i = 0, &r1 = i; double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
```
## [Exercise 2.17](Chapter02/2.17.cpp)
What does the following code print?
```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
## [Exercise 2.18](Chapter02/2.18.cpp)
Write code to change the value of a pointer. Write code to change the
value to which the pointer points.
## [Exercise 2.19](Chapter02/2.19.txt)
Explain the key differences between pointers and references.
## [Exercise 2.20](Chapter02/2.20.cpp)
What does the following program do?
```
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```
## [Exercise 2.21](Chapter02/2.21.cpp)
Explain each of the following definitions. Indicate whether any are il-
legal and, if so, why.
```
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```
## [Exercise 2.22](Chapter02/2.22.cpp)
Assuming p is a pointer to int, explain the following code:
```
if (p) // ...
if (*p) // ...
```
## [Exercise 2.23](Chapter02/2.23.txt)
Given a pointer p, can you determine whether p points to a valid object?
If so, how? If not, why not?
## [Exercise 2.24](Chapter02/2.24.cpp)
Why is the initialization of p legal but that of lp illegal?
```
int i = 42;
void *p = &i;
long *lp = &i;
```
## [Exercise 2.25](Chapter02/2.25.cpp)
Determine the types and values of each of the following variables.
```
(a) int* ip, i, &r = i;
(b) int i, *ip = 0;
(c) int* ip, ip2;
```
## [Exercise 2.26](Chapter02/2.26.cpp)
Which of the following are legal? For those that are illegal, explain why.
```
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;
```
## [Exercise 2.27](Chapter02/2.27.txt)
Which of the following initializations are legal? Explain why.
```
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;
```
## [Exercise 2.28](Chapter02/2.28.txt)
Explain the following definitions. Identify any that are illegal.
```
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
```
## [Exercise 2.29](Chapter02/2.29.txt)
Uing the variables in the previous exercise, which of the following as-
signments are legal? Explain why.
```
(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;
```
## [Exercise 2.30](Chapter02/2.30.txt)
For each of the following declarations indicate whether the object being
declared has top-level or low-level const.
```
const int v2 = 0;
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
## [Exercise 2.31](Chapter02/2.31.txt)
Given the declarations in the previous exercise determine whether the
following assignments are legal. Explain how the top-level or low-level const applies
in each case.
```
r1 = v2;
p1 = p2;
p2 = p1;
p1 = p3;
p2 = p3;
```
## [Exercise 2.32](Chapter02/2.32.cpp)
Is the following code legal or not? If not, how might you make it legal?
```
int null = 0, *p = null;
```
## [Exercise 2.33](Chapter02/2.33.txt)
Using the variable definitions from this section, determine what hap-
pens in each of these assignments:
```
a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```
## [Exercise 2.34](Chapter02/2.34.cpp)
Write a program containing the variables and assignments from the
previous exercise. Print the variables before and after the assignments to check
whether your predictions in the previous exercise were correct. If not, study the exam-
ples until you can convince yourself you know what led you to the wrong conclusion.
## [Exercise 2.35](Chapter02/2.35.txt)
Determine the types deduced in each of the following definitions. Once
you’ve figured out the types, write a program to see whether you were correct.
```
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i;
const auto j2 = i, &k2 = i;
```
## [Exercise 2.36](Chapter02/2.36.txt)
In the following code, determine the type of each variable and the value
each variable has when the code finishes:
```
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
## [Exercise 2.37](Chapter02/2.37.txt)
Assignment is an example of an expression that yields a reference type.
The type is a reference to the type of the left-hand operand. That is, if i is an int, then
the type of the expression i = x is int&. Using that knowledge, determine the type
and value of each variable in this code:
```
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
## [Exercise 2.38](Chapter02/2.38.txt)
Describe the differences in type deduction between decltype and
auto. Give an example of an expression where auto and decltype will deduce
the same type and an example where they will deduce differing types.
## [Exercise 2.39](Chapter02/2.39.cpp)
Compile the following program to see what happens when you forget
the semicolon after a class definition. Remember the message for future reference.
```
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
  return 0;
}
```
## [Exercise 2.40](Chapter02/2.40.cpp)
Write your own version of the Sales_data class.
## [Exercise 2.41](Chapter02/2.41.cpp)
Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22),
§ 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in
the same file as your main function.
## [Exercise 2.42](Chapter02/2.42.cpp)
Write your own version of the Sales_data.h header and use it to
rewrite the exercise from § 2.6.2 (p. 76).
